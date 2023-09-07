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
        lol p[n];
        lol in[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> p[i];
            in[p[i] - 1] = i;
        }
        lol ans = 0;
        for (lol i = 1; i < n; i++)
        {
            if (in[i] < in[i - 1])
            {
                ans++;
            }
        }
        cout << ans << '\n';
    }
}