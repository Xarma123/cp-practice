#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol t;
    cin >> t;
    while (t--)
    {
        lol n;
        cin >> n;
        lol a[n];
        multiset<lol> x;
        lol ans = 0;
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
            if (a[i] == 0)
            {
                if (!x.empty())
                {
                    ans += -(*x.begin());
                    x.erase(x.begin());
                }
            }
            else
                x.insert(-a[i]);
        }
        cout << ans << '\n';
    }

    return 0;
}