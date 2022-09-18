#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, p;
    cin >> n >> p;
    string s;
    cin >> s;
    lol ca = 0;
    lol st = 0, e = n - 1;
    lol l = -1;
    lol lmx;
    lol r = -1;
    lol rmn;
    while (st < e)
    {
        if (s[st] != s[e])
        {
            ca += min(abs(s[st] - s[e]), 26 - abs(s[st] - s[e]));
            if (l == -1)
                l = st;
            lmx = st;
            if (r == -1)
                r = e;
            rmn = e;
        }
        st++;
        e--;
    }
    if (l == -1)
        cout << 0;
    else
    {
        // l lmx
        lol a1;
        if (p - 1 <= l)
            a1 = lmx - (p - 1);
        else if (p - 1 >= lmx)
            a1 = p - 1 - l;
        else
        {
            a1 = min(lmx - (p - 1), (p - 1) - l);
            a1 += (lmx - l);
        }
        // rmn  r
        lol a2;
        if (p - 1 <= rmn)
            a2 = r - (p - 1);
        else if (p - 1 >= r)
            a2 = p - 1 - rmn;
        else
        {
            a2 = min(r - (p - 1), (p - 1) - rmn);
            a2 += r - rmn;
        }
        cout << min(a1, a2) + ca;
    }

    return 0;
}