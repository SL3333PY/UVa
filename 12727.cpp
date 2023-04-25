#include <bits/stdc++.h>
using namespace std;

struct binocular
{
    int a, b, c;
}B[35];

int t, n, m, k;
bool C[310];    //�O��cost��i����׬O�_�s�b

bool cmp(binocular x, binocular y)
{
    if (x.a != y.a) return x.a < y.a;
    return x.b < y.b;
}

void dfs(int l, int r, int num, int cost)
{
    if (r == n) {
        C[cost] = true;
        return;
    }

    for (int i = num; i <= m; i++) {
        if (B[i].a > l && B[i].a <= r + 1 && B[i].b > r)
            dfs(r + 1, B[i].b, i + 1, cost + B[i].c);
    }
}

int main()
{
    scanf("%d", &t);
    for (int cas = 1; cas <= t; cas++) {
        scanf("%d%d%d", &n, &m, &k);
        for (int i = 1; i <= m; i++) {
            scanf("%d%d%d", &B[i].a, &B[i].b, &B[i].c);
        }
        sort(B+1, B+1+m, cmp);

        memset(C, 0, sizeof(C));
        dfs(0, 0, 1, 0);

        long long ans = 0;
        int x, y;
        while (k--) {
            scanf("%d%d", &x, &y);
            for (int i = 305; i >= 1; i--) {        //�C�H�̰��i���O��30*10
                if (C[i] && y >= x && y >= i) {     //cost��i�i�� & �٦��H���B�z & �w�⨬��
                    if (x >= i) ans += (long long) i * (y - x + 1);     //�Ҧ��H�w��Ҩ���
                    else ans += (long long) i * (y - i + 1);
                    y = i - 1;
                }
            }
        }
        printf("Case #%d: %lld\n", cas, ans);
    }
}
