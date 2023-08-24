#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol t;
    cin >> t;
    while (t--)
    {
        lol a, b, c;
        cin >> a >> b >> c;
        lol ans = LONG_LONG_MAX;
        lol A, B, C;
        for (lol i = 1; i <= c; i++)
        {
            vector<lol> d;
            vector<lol> d2;
            for (lol j = 1; j * 1ll * j <= i; j++)
            {
                if (i % j == 0)
                {
                    d.push_back(j);
                    if (i / j != j)
                        d2.push_back((i / j));
                }
            }
            reverse(d2.begin(), d2.end());
            for (auto e : d2)
            {
                d.push_back(e);
            }
            lol j = lower_bound(d.begin(), d.end(), a) - d.begin();
            lol a1, a2, a3;
            lol v1 = INT_MAX;
            if (j < d.size())
            {
                if (v1 > d[j] - a)
                    a1 = d[j];
                v1 = min(v1, d[j] - a);
            }
            j--;
            if (j >= 0)
            {
                if (v1 > a - d[j])
                    a1 = d[j];
                v1 = min(v1, a - d[j]);
            }
            v1 += abs(i - b);
            a2 = i;
            if (c < i)
            {
                v1 += i - c;
                a3 = i;
            }
            else if (i < c)
            {

                v1 += min((c % i), i - (c % i));
                if ((c % i) < i - (c % i))
                    a3 = c - (c % i);
                else
                    a3 = c + i - (c % i);
            }
            else
            a3=c;
            if (ans > v1)
            {
                A = a1, B = a2, C = a3;
            }
            ans = min(ans, v1);
        }
        for (lol i = 1; i <= c; i++)
        {

            lol top = (long long)ceill(c / (long double)i) * 1ll * i;
            if (top - b + top - c +abs(a-i)< ans)
            {
                ans = top - b + top - c+abs(a-i);
                A = i;
                B = top;
                C = top;
            }
        }
        cout << ans << '\n';
        cout << A << " " << B << " " << C << '\n';
    }
}