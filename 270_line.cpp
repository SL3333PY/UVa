#include <bits/stdc++.h>
using namespace std;

struct point
{
    int x, y;
} p[705];

bool cross(int i, int j, int k)
{
    int x1 = p[j].x - p[i].x;
    int y1 = p[j].y - p[i].y;
    int x2 = p[k].x - p[i].x;
    int y2 = p[k].y - p[i].y;
    return x1 * y2 == x2 * y1;
}

int main()
{
    int n;
    char num[100];
    cin >> n;
    getchar();
    getchar();
    while (n--) {
        int l = 0;
        while (gets(num)) {
            if (num[0] =='\0') break;
            sscanf(num, "%d %d", &p[l].x, &p[l].y);
            l++;
        }

        int maxn = 0;

        for (int i = 0; i < l; i++) {
            for (int j = i + 1; j < l; j++) {
                int tmp = 2;
                for (int k = j + 1; k < l; k++) {
                    if (cross(i, j, k)) tmp++;
                }
                maxn = max(maxn, tmp);
            }
        }
        cout << maxn << "\n";
        if (n) cout << "\n";
    }

    return 0;
}
