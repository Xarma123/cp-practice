#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n;
    cin >> n;
    string a[n];
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    lol ans = 0;
    for (lol i = 0; i < n; i++)
    {
        lol r = 0;
        for (lol j = 0; j < n; j++)
        {
            bool c = true;
            for (lol k = 0; k < n; k++)
            {
                if (a[i][k] == '0')
                {
                    if (a[j][k] == '1')
                        c = false;
                }
                else
                {
                    if (a[j][k] == '0')
                        c = false;
                }
            }
            r += c;
        }
        ans = max(ans, r);
    }
    cout << ans;

    return 0;
}