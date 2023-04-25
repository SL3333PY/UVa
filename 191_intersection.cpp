#include <bits/stdc++.h>
using namespace std;

struct point
{
    int x, y;
};

point st, ed;
int l, r, t, b;
point lt, lb, rt, rb;


int cross(point a, point b, point c)    // ab cross ac
{
    return (b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y);
}

int dot(point a, point b, point c)      //ab dot ac
{
    return (b.x - a.x) * (c.x - a.x) + (b.y - a.y) * (c.y - a.y);
}

bool check()
{
    if (
        max(st.x, ed.x) < l ||
        max(st.y, ed.y) < b ||
        r < min(st.x, ed.x) ||
        t < min(st.y, ed.y)
        ) return 0;

    if (
        st.x <= r && st.x >= l && st.y <= t && st.y >= b || // start point in the rectangle
        ed.x <= r && ed.x >= l && ed.y <= t && ed.y >= b    // end point in the rectangle
        ) return 1;

    int lt_l = cross(lt, st, ed);
    int rt_l = cross(rt, st, ed);
    int lb_l = cross(lb, st, ed);
    int rb_l = cross(rb, st, ed);

    if (
        cross(st, lt, rt) * cross(ed, lt, rt) < 0 && lt_l * rt_l < 0 ||    // intersect with top
        cross(st, lb, rb) * cross(ed, lb, rb) < 0 && lb_l * rb_l < 0 ||    // intersect with bottom
        cross(st, lt, lb) * cross(ed, lt, lb) < 0 && lt_l * lb_l < 0 ||    // intersect with left
        cross(st, rt, rb) * cross(ed, rt, rb) < 0 && rt_l * rb_l < 0       // intersect with right
        ) return 1;

    if (lt_l == 0) return dot(lt, st, ed) <= 0;
    if (rt_l == 0) return dot(rt, st, ed) <= 0;
    if (lb_l == 0) return dot(lb, st, ed) <= 0;
    if (rb_l == 0) return dot(rb, st, ed) <= 0;

    return 0;
}

int main()
{
    int n;
    cin >> n;
    while (n--) {
        cin >> st.x >> st.y >> ed.x >> ed.y >> l >> t >> r >> b;
        if (l > r)
            swap(l, r);
        if (b > t)
            swap(b, t);

        lt.x = l; lt.y = t; // left-top
        lb.x = l; lb.y = b; // left-bottom
        rt.x = r; rt.y = t; // right-top
        rb.x = r; rb.y = b; // right-bottom

        if (check())
            cout << "T\n";
        else
            cout << "F\n";
    }

    return 0;
}
