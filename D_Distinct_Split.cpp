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
        string s;
        cin >> s;
        lol cl[n];
        lol cr[n];
        set<char> x;
        for (lol i = 0; i < n; i++)
        {
            x.insert(s[i]);
            cl[i] = x.size();
        }
        x.clear();
        for (lol i = n - 1; i >= 0; i--)
        {
            x.insert(s[i]);
            cr[i] = x.size();
        }
        lol ans = LONG_LONG_MIN;
        for (lol i = 0; i < n - 1; i++)
        {
            ans = max(ans, cl[i] + cr[i + 1]);
        }
        cout << ans << '\n';
    }

    return 0;
}