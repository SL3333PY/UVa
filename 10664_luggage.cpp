#include <bits/stdc++.h>
using namespace std;

int w[25], dp[205];     //dp[j] = �ण���X���qj

int main()
{
    int s;
    char c;
    scanf("%d%c", &s, &c);
    while (s--) {
        int cnt = 0, sum = 0;
        while (scanf("%d%c", &w[cnt], &c)) {
            sum += w[cnt];
            cnt++;
            if (c == '\n') break;
        }
        if (sum % 2) {
            printf("NO\n");         //�p�G����㰣2 = �������b
            continue;
        }
        //printf("%d\n", sum);
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;      //0 kg�@�w�i
        for (int i = 0; i < cnt; i++) {             //�C�Ӧ��
            for (int j = sum / 2; j >= w[i]; j--)   //�̤j�u�ݭn���Dsum / 2�椣��A�p�Gj<�o�Ӧ�����A��j�N���i���Q�o�Ӧ������X��
                if (dp[j - w[i]]) dp[j] = 1;        //�p�G���qj-�o�Ӧ�����i�H��X�ӡA�N���qj�]�i�H��X�ӡA�]��1
        }
        //printf("%d\n", dp[sum / 2]);

        if (dp[sum / 2]) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
