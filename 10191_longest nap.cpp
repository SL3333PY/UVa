#include <bits/stdc++.h>
using namespace std;

struct Time
{
    int h;
    int m;
};

struct Thing
{
    Time st;
    Time ed;
};
Thing all[105];

bool compare(Thing a, Thing b)
{
    if (a.st.h < b.st.h) return true;
    else if (a.st.h == b.st.h && a.st.m < b.st.m) return true;
    return false;
}

int main()
{
    int s, cnt = 0;
    string x;
    while (scanf("%d", &s) != EOF) {
        cnt++;
        for (int i = 0; i < s; i++) {
            scanf("%d:%d %d:%d", &all[i].st.h, &all[i].st.m, &all[i].ed.h, &all[i].ed.m);
            getline(cin, x);
        }

        sort(all, all+s, compare);

        int nap = (all[0].st.h - 10) * 60 + all[0].st.m;
        Time ns;
        ns.h = 10;
        ns.m = 0;

        for (int i = 1; i < s; i++) {
            int tem = (all[i].st.h - all[i-1].ed.h) * 60 + all[i].st.m - all[i-1].ed.m;
            if (nap < tem) {
                nap = tem;
                ns.h = all[i-1].ed.h;
                ns.m = all[i-1].ed.m;
            }
        }
        if (nap < (18 - all[s-1].ed.h) * 60 - all[s-1].ed.m) {
            nap = (18 - all[s-1].ed.h) * 60 - all[s-1].ed.m;
            ns.h = all[s-1].ed.h;
            ns.m = all[s-1].ed.m;
        }

        if (s == 0) {
            nap = 8 * 60;
            ns.h = 10;
            ns.m = 0;
        }

        printf("Day #%d: the longest nap starts at %02d:%02d and will last for ", cnt, ns.h, ns.m);
        if (nap >= 60) printf("%d hours and ", nap / 60);
        printf("%d minutes.\n", nap % 60);

    }
    return 0;
}
