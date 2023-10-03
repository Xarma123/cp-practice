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
        lol l = -1, r = -1;
        for (lol i = 0; i < s.size(); i++)
        {
            if (s[i] == '1')
            {
                if (l == -1)
                    l = i;
                r = i;
            }
        }
        if (l == -1)
        {
            cout << n << '\n';
        }
        else
        {
            cout << max(2ll * (r + 1), max((n - l) * 2ll, n + r - l + 1)) << '\n';
        }
    }
}