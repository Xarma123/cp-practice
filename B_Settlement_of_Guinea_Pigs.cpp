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
        lol x = 0;
        lol ans = 0;
        lol khali = 0;
        for (lol i = 0; i < n; i++)
        {
            lol v;
            cin >> v;
            if (v == 1)
            {
                if (khali > 0)
                {
                    khali--;
                    x++;
                }
                else
                {
                    ans++;
                    x++;
                }
            }
            else
            {
                if (x > 2)
                {
                    if (x % 2 == 0)
                        khali += (x / 2) - 1;
                    else
                        khali += (x / 2);
                    if (x % 2)
                        x = 1;
                    else
                        x = 2;
                }
            }
        }
        cout << ans << endl;
    }

    return 0;
}