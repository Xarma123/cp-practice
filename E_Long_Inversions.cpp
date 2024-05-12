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
        lol ans = 0;
        for (lol i = 1; i <= n; i++)
        {
            lol c = 0;
            lol f[n];
            memset(f, 0, sizeof(f));
            bool q = true;

            for (lol j = 0; j < n; j++)
            {
                c += f[j];

                if ((s[j] == '0' && (c % 2 == 0)) || (s[j] == '1' && (c % 2 != 0)))
                {
                    if (j + i - 1 < n)
                    {
                        c++;
                        if (j + i < n)
                            f[j + i]--;
                    }
                    else
                    {
                        q = false;
                        break;
                    }
                }
            }
            if (q)
                ans = i;
        }
        cout << ans << '\n';
    }

    return 0;
}
