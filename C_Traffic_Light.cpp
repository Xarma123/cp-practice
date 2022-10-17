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
        char c;
        cin >> c;
        string s;
        cin >> s;
        s = s + s;

        lol r = -1;
        lol ans = LONG_LONG_MIN;
        for (lol i = s.size() - 1; i >= 0; i--)
        {
            if (s[i] == 'g')
            {
                r = i;
            }
            if (s[i] == c)
            {
                if (r != -1)
                {
                    ans = max(ans, (r - i));
                }
            }
        }
        cout << ans << endl;
    }

    return 0;
}