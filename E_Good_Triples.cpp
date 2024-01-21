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
        string s;
        cin >> s;
        lol ans = 1;
        for (auto e : s)
        {
            lol v = e - '0';
            lol c = 0;
            for (lol i = 0; i <= 9; i++)
            {
                for (lol j = 0; j <= 9; j++)
                {
                    for (lol k = 0; k <= 9; k++)
                    {
                        if (i + j + k == v)
                        {
                            c++;
                        }
                    }
                }
            }
            ans = ans * 1ll * c;
        }
        cout << ans << '\n';
    }

    return 0;
}
