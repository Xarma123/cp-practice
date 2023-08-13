#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol x, y, ax, ay, bx, by;
    cin >> x >> y >> ax >> ay >> bx >> by;
    vector<pair<lol, lol>> v;
    v.push_back({x, y});
    lol xs, ys, t;
    cin >> xs >> ys >> t;

    unsigned long long x1 = x, y1 = y;
    while (x1 <= (unsigned long long)2e16 && y1 <= (unsigned long long)2e16)
    {
        x1 = x1 * ax + bx;
        y1 = y1 * ay + by;
        v.push_back({(long long)x1, (long long)y1});
    }
    lol ans = 0;
    for (lol i = 0; i < v.size(); i++)
    {
        lol T = t - (long long)abs(xs - v[i].first) - (long long)abs(ys - v[i].second);
        if (T >= 0)
        {
            for (lol j = i - 1; j >= 0; j--)
            {
                if ((long long)abs(v[j].first - v[i].first) + (long long)abs(v[j].second - v[i].second) <= T)
                {
                    lol TT = T - ((long long)abs(v[j].first - v[i].first) + (long long)abs(v[j].second - v[i].second));
                    lol s = j, e = v.size();
                    while (s != e - 1)
                    {
                        lol m = (s + e) / 2ll;
                        if (m == v.size())
                        {
                            e = m;
                        }
                        else
                        {
                            if ((long long)abs(v[m].first - v[j].first) + (long long)abs(v[m].second - v[j].second) <= TT)
                            {
                                s = m;
                            }
                            else
                                e = m;
                        }
                    }
                    if (e > i)
                    {
                        ans = max(ans, s - j + 1);
                    }
                }
                else
                    break;
            }
        }
        if (T >= 0)
        {
            for (lol j = i + 1; j < v.size(); j++)
            {
                if ((long long)abs(v[j].first - v[i].first) + (long long)abs(v[j].second - v[i].second) <= T)
                {
                    lol TT = T - ((long long)abs(v[j].first - v[i].first) + (long long)abs(v[j].second - v[i].second));
                    lol s = -1, e = j;
                    while (s != e - 1)
                    {
                        lol m = (s + e) / 2ll;
                        if (m == -1)
                        {
                            s = m;
                        }
                        else
                        {
                            if ((long long)abs(v[m].first - v[j].first) + (long long)abs(v[m].second - v[j].second) <= TT)
                            {
                                e = m;
                            }
                            else
                                s = m;
                        }
                    }
                    if (e < i)
                    {
                        ans = max(ans, j - e + 1);
                    }
                }
                else
                    break;
            }
        }
        if (T >= 0)
        {
            lol s = -1, e = i;
            while (s != e - 1)
            {
                lol m = (s + e) / 2ll;
                if (m == -1)
                {
                    s = m;
                }
                else
                {
                    if ((long long)abs(v[m].first - v[i].first) + (long long)abs(v[m].second - v[i].second) <= T)
                    {
                        e = m;
                    }
                    else
                        s = m;
                }
            }
            ans = max(ans, i - e + 1);
            s = i, e = v.size();
            while (s != e - 1)
            {
                lol m = (s + e) / 2ll;
                if (m == v.size())
                {
                    e = m;
                }
                else
                {
                    if ((long long)abs(v[m].first - v[i].first) + (long long)abs(v[m].second - v[i].second) <= T)
                    {
                        s = m;
                    }
                    else
                        e = m;
                }
            }
            ans = max(ans, s - i + 1);
        }
    }
    cout << ans;
}