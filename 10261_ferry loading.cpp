#include <bits/stdc++.h>
using namespace std;

int dp[2005][10005], w[2005], sum[2005];

int main()
{
    int s, x;
    cin >> s;
    while (s--) {
        int max_len, final_len, final_car, cnt;      //車道長、最終放入總長、最終放入車數
        queue<bool> q;       //存左右
        cin >> max_len;
        max_len *= 100;
        sum[0] = 0;
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;
        while (cin >> x && x != 0) {
            ++cnt;
            w[cnt] = x;
            sum[cnt] += x;
        }
        for (int i = 1; i < cnt; i++) {
            for (int j = 0; j < max_len; j++) {
                if (j >= w[i] && dp[i - 1][j - w[i]] == 1) {     //放左邊
                    final_car = i;
                    final_len = j;
                    dp[i][j] = 1;
                    q.push(0);
                }
                else if (sum[i] - j <= max_len && dp[i - 1][j] == 1) {   //放右邊
                    final_car = i;
                    final_len = j;
                    dp[i][j] = 1;
                    q.push(1);
                }
            }
        }
        cout << final_car << "\n";
        while (!q.empty()) {
            if (q.front() == 0) cout << "port\n";
            else if (q.front() == 1) cout << "starboard\n";
            q.pop();
        }
    }
    return 0;
}

// 未完成
