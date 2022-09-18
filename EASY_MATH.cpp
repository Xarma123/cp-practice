#include <bits/stdc++.h>
#define lol unsigned long long
using namespace std;
lol lcm(vector<lol> a)
{
    lol lcm = a[0];
    for (lol i = 1; i < a.size(); i++)
    {
        lcm = lcm * 1ll * a[i] / __gcd(a[i], lcm);
    }
    return lcm;
}
lol n, m;
lol count(lol v)
{
    lol k2 = m / v;
    lol k1 = ceill(n / (long double)v);
    return k2 - k1 + 1;
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol t;
    cin >> t;
    while (t--)
    {

        lol a, d;
        cin >> n >> m >> a >> d;
        lol ans = 0;
        vector<lol> q;
        q.push_back(a);
        for (lol i = 0; i < 4; i++)
        {
            q.push_back(q.back() + d);
        }

        for (lol i = 0; i < 5; i++)
        {

            ans += count(q[i]);
        }

        for (lol i = 0; i < 5; i++)
        {
            for (lol j = i + 1; j < 5; j++)
            {
                ans -= count(lcm({q[i], q[j]}));
            }
        }
        for (lol i = 0; i < 5; i++)
        {
            for (lol j = i + 1; j < 5; j++)
            {
                for (lol k = j + 1; k < 5; k++)
                {
                    ans += count(lcm({q[i], q[j], q[k]}));
                }
            }
        }
        for (lol i = 0; i < 5; i++)
        {
            for (lol j = i + 1; j < 5; j++)
            {
                for (lol k = j + 1; k < 5; k++)
                {
                    for (lol k1 = k + 1; k1 < 5; k1++)
                    {

                        ans -= count(lcm({q[i], q[j], q[k], q[k1]}));
                    }
                }
            }
        }
        for (lol i = 0; i < 5; i++)
        {
            for (lol j = i + 1; j < 5; j++)
            {
                for (lol k = j + 1; k < 5; k++)
                {
                    for (lol k1 = k + 1; k1 < 5; k1++)
                    {
                        for (lol k2 = k1 + 1; k2 < 5; k2++)
                        {

                            ans += count(lcm({q[i], q[j], q[k], q[k1], q[k2]}));
                        }
                    }
                }
            }
        }
        cout << m - n + 1 - ans << endl;
    }
    return 0;
}