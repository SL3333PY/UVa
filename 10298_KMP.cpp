#include <bits/stdc++.h>
using namespace std;

int nxt[1000005];

int main()
{
    string s;
    while (cin >> s && s!= ".") {
        int len = s.length();
        int k = -1;
        nxt[0] = -1;
        for(int i = 1; i < len; ++i) {
            while(k != -1 && s[i] != s[k+1]) k = nxt[k];

            if(s[i] == s[k+1]) k++;
            nxt[i] = k;
        }
        int n = len - 1;
        if((n + 1) % (n - nxt[n]) == 0) cout << (n + 1) / (n - nxt[n]) << "\n";
        else cout << "1\n";
    }
    return 0;
}
