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
    lol h[n], g[n];
    for (lol i = 0; i < n; i++)
    {
        cin >> h[i] >> g[i];
    }
    lol ans = 0;
    for (lol i = 0; i < n; i++)
    {
        for (lol j = 0; j < n; j++)
        {
            if (i != j && h[i] == g[j])
            {
                ans++;
            }
        }
    }
    cout << ans;

    return 0;
}