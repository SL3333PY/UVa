#include <bits/stdc++.h>
using namespace std;

int w[25], dp[205];     //dp[j] = 能不能湊出重量j

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
            printf("NO\n");         //如果不能整除2 = 不能分兩半
            continue;
        }
        //printf("%d\n", sum);
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;      //0 kg一定可
        for (int i = 0; i < cnt; i++) {             //每個行李
            for (int j = sum / 2; j >= w[i]; j--)   //最大只需要知道sum / 2行不行，如果j<這個行李重，那j就不可能能被這個行李重湊出來
                if (dp[j - w[i]]) dp[j] = 1;        //如果重量j-這個行李重可以湊出來，代表重量j也可以湊出來，設為1
        }
        //printf("%d\n", dp[sum / 2]);

        if (dp[sum / 2]) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
