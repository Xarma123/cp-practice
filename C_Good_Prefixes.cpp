#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol t;
    cin >> t;
    while (t--)
    {
        lol n;
        cin >> n;
        lol a[n];
        set<lol> x;
        lol sum = 0;
        lol ans = 0;
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
            x.insert(a[i]);
            sum += a[i];
            if ((sum % 2) == 0)
            {
                if (x.count((sum / 2ll)))
                {
                    ans++;
                }
            }
        }
        cout << ans << '\n';
    }

    return 0;
}
