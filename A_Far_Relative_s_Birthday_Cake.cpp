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
        lol q = 0, q2 = 0;
        for (lol j = 0; j < n; j++)
        {
            if (a[i][j] == 'C')
                q++;
            if (a[j][i] == 'C')
                q2++;
        }
        ans += q * 1ll * (q - 1) / 2ll;
        ans += q2 * 1ll * (q2 - 1) / 2ll;
    }
    cout << ans;

    return 0;
}