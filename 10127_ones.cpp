#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    while (cin >> n) {
        int test = 1;
        int cnt = 1;
        while (test % n != 0) {
            test %= n;
            test *= 10;
            test++;
            cnt++;
        }
        cout << cnt << "\n";
    }
    return 0;
}
