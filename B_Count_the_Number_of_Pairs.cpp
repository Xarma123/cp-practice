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
        lol n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        lol d = 'A' - 'a';
        lol ans = 0;
        for (char a = 'a'; a <= 'z'; a++)
        {
            lol x = 0, y = 0;
            for (auto c : s)
            {
                if (c == a)
                    x++;
                else if (c == char(a + d))
                    y++;
            }
            if (x < y)
                swap(x, y);
            ans += y;
            ans += min((x - y) / 2, k);
            k -= min((x - y) / 2, k);
        }
        cout << ans << endl;
    }

    return 0;
}