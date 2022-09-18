#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol xa, ya, xb, yb;
    cin >> xa >> ya >> xb >> yb;
    lol n;
    cin >> n;
    vector<vector<lol>> circle;
    while (n--)
    {
        lol x, y, r;
        cin >> x >> y >> r;
        circle.push_back({x, y, r});
    }
    lol ans = 0;
    if (ya > yb)
    {
        for (lol i = yb; i <= ya; i++)
        {
            bool f = false, f2 = false;
            for (auto e : circle)
            {
                lol x = e[0], y = e[1], r = e[2];
                if ((x - xa) * (x - xa) + (y - i) * (y - i) <= r * r)
                    f = true;
                if ((x - xb) * (x - xb) + (y - i) * (y - i) <= r * r)
                    f2 = true;
            }
            if (!f)
                ans++;
            if (!f2)
                ans++;
        }
    }
    else
    {
        for (lol i = ya; i <= yb; i++)
        {
            bool f = false, f2 = false;
            for (auto e : circle)
            {
                lol x = e[0], y = e[1], r = e[2];
                if ((x - xa) * (x - xa) + (y - i) * (y - i) <= r * r)
                    f = true;
                if ((x - xb) * (x - xb) + (y - i) * (y - i) <= r * r)
                    f2 = true;
            }
            if (!f)
                ans++;
            if (!f2)
                ans++;
        }
    }
    if (xa > xb)
    {
        for (lol i = xb+1; i < xa; i++)
        {
            bool f = false, f2 = false;
            for (auto e : circle)
            {
                lol x = e[0], y = e[1], r = e[2];
                if ((x - i) * (x - i) + (y - ya) * (y - ya) <= r * r)
                    f = true;
                if ((x - i) * (x - i) + (y - yb) * (y - yb) <= r * r)
                    f2 = true;
            }
            if (!f)
                ans++;
            if (!f2)
                ans++;
        }
    }
    else
    {
        for (lol i = xa+1; i < xb; i++)
        {
            bool f = false, f2 = false;
            for (auto e : circle)
            {
                lol x = e[0], y = e[1], r = e[2];
                if ((x - i) * (x - i) + (y - ya) * (y - ya) <= r * r)
                    f = true;
                if ((x - i) * (x - i) + (y - yb) * (y - yb) <= r * r)
                    f2 = true;
            }
            if (!f)
                ans++;
            if (!f2)
                ans++;
        }
    }
    cout << ans;

    return 0;
}