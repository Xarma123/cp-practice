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
        lol n, c;
        cin >> n >> c;
        lol a[n];
        multiset<lol> x;
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
            x.insert((a[i] + i + 1));
        }
        lol ans = 0;
        while (!x.empty() && (*x.begin()) <= c)
        {
            ans++;
            c -= (*x.begin());
            x.erase(x.begin());
        }
        cout << ans << '\n';
    }

    return 0;
}