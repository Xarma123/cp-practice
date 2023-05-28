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
        string s;
        cin >> s;
        lol ans = 0;
        for (lol i = 0; i < s.size(); i++)
        {
            if (s[i] == '_')
            {
                if (i == 0)
                {
                    ans++;
                }
                if (i + 1 < s.size() && s[i + 1] != '^')
                {

                    ans++;
                }
                if (i + 1 >= s.size())
                {
                    ans++;
                }
            }
        }
        if (s == "^")
            ans++;

        cout << ans << '\n';
    }

    return 0;
}