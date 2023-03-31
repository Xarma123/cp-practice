#include <bits/stdc++.h>
#define lol long long
using namespace std;
lol solve(string x)
{
    lol mn = 11;
    lol mx = -1;
    for (auto e : x)
    {
        mn = min(mn, (long long)(e - '0'));
        mx = max(mx, (long long)(e - '0'));
    }
    return mx - mn;
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
        string l, r;
        cin >> l >> r;
        if (l == r)
            cout << l << '\n';
        else if (l.size() == 1)
            cout << l << '\n';
        else if (r.size() >= l.size() + 1)
        {
            for (lol i = 0; i < l.size(); i++)
            {
                cout << 9;
            }
            cout << '\n';
        }
        else
        {
            string ans = "";
            lol c = LONG_LONG_MAX;
            for (lol i = 0; i <= 9; i++)
            {
                for (lol j = i; j <= 9; j++)
                {
                    for (lol k = 0; k < l.size(); k++)
                    {
                        // at k we want j
                        // before k we want values =l
                        // after k we want i
                        string q = l;
                        q[k] = char('0' + j);
                        for (lol x = k + 1; x < l.size(); x++)
                        {
                            q[x] = char('0' + i);
                        }

                        if (q >= l && q <= r && solve(q) < c)
                        {
                            c = solve(q);
                            ans = q;
                        }
                    }
                }
            } 
            

            cout << ans << '\n';
        }
    }

    return 0;
}