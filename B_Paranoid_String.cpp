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
        lol ans = 0;
        for (lol i = 1; i < n; i++)
        {
            if (s[i] == '1' && s[i - 1] == '0')
                ans += i;
        }
        // 10
        for (lol i = 1; i < n; i++)
        {
            if (s[i] == '0' && s[i - 1] == '1')
                ans += i;
        }
        ans += n;
        cout << ans << endl;
    }

    return 0;
}