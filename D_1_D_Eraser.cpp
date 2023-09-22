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
        lol n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        lol ans = 0;
        for (lol i = 0; i < n; i++)
        {
            if (s[i] == 'B')
            {
                ans++;
                i += k - 1;
            }
        }
        cout << ans << '\n';
    }
}