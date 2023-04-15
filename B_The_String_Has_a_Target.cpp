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
        char mn = 'z';
        for (auto c : s)
        {
            mn = min(mn, c);
        }
        lol i;
        for (i = s.size() - 1; i >= 0; i--)
        {
            if (s[i] == mn)
                break;
        }
        cout << mn;
        for (lol j = 0; j < n; j++)
        {
            if (j == i)
                continue;
            cout << s[j];
        }
        cout << '\n';
    }

    return 0;
}