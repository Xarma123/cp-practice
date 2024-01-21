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
        string s;
        cin >> s;
        lol f[26];
        memset(f, 0, sizeof(f));
        lol mx = 0;
        for (auto e : s)
        {
            f[e - 'a']++;
            mx = max(mx, f[e - 'a']);
        }
        if (mx <= n - mx)
        {
            cout << (n % 2) << '\n';
        }
        else
            cout << mx - (n - mx) << '\n';
    }

    return 0;
}
