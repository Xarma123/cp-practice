#include <bits/stdc++.h>
#define lol long long
using namespace std;
lol n, d;
vector<long double> a;
pair<lol, lol> check(long double x)
{
    long double p[n];
    long double m[n];
    p[0] = a[0] - x;
    m[0] = a[0] - x;
    for (lol i = 1; i < n; i++)
    {
        p[i] = p[i - 1] + a[i] - x;
        m[i] = min(p[i], m[i - 1]);
    }
    pair<lol, lol> f = make_pair(-1, -1);
    for (lol r = 0; r < n; r++)
    {
        if (r - d-1 >= -1)
        {
            if (r - d -1 != -1)
            {
                if (m[r - d -1] <= p[r])
                {
                    f.first = r - d +1;
                    f.second = r +1;
                  
                }
            }
            else
            {
                if (p[r] >= 0)
                {
                    f.first = r - d + 1;
                    f.second = r + 1;
                   
                }
            }
        }
    }
    return f;
}
int main()
{

    cin >> n >> d;

    long double e = 0;
    for (lol i = 0; i < n; i++)
    {
        long double t;
        cin >> t;
        a.push_back(t);
        e = max(a[i], e);
    }
    long double s = 0;
    for (lol i = 0; i < d; i++)
    {
        s += a[i];
    }
    s = s / d;
    e = e + 2;

    pair<lol, lol> ans = make_pair(1, d + 1);
    while (s != e - 1)
    {

        long double m = (s + e) / 2;
        pair<lol, lol> t = check(m);
        if (t.first != -1)
        {

            s = m;
            ans = t;
        }
        else
            e = m;
    }
    cout << ans.first << " " << ans.second << ' ';
    return 0;
}