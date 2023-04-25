#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    int top, north, west;
    int tmp;
    string s;
    while (cin >> t && t) {
        top = 1;    north = 2; west = 3;
        for (int command = 0; command < t; command++) {
            cin >> s;
            if (s == "north") {
                tmp = top;
                top = 7 - north;
                north = tmp;
            }
            else if (s == "south") {
                tmp = top;
                top = north;
                north = 7 - tmp;
            }
            else if (s == "west") {
                tmp = top;
                top = 7 - west;
                west = tmp;
            }
            else if (s == "east") {
                tmp = top;
                top = west;
                west = 7 - tmp;
            }
        }
        cout << top << endl;
    }
    return 0;
}
