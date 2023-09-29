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
        lol n;
        cin >> n;
        string s;
        cin >> s;
        lol ans = 0;
        for (lol i = 0; i < n; i++)
        {
            if (s[i] == 'A')
            {
                lol j = i + 1;
                while (j < n && s[j] == 'P')
                    j++;
                ans = max(ans, j - i - 1);
                i = j - 1;
            }
        }
        cout << ans << '\n';
    }
}