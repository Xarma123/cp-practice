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
    lol h[n];
    for (lol i = 0; i < n; i++)
    {
        cin >> h[i];
    }
    lol ans[n];
    lol mx = 0;
    for (lol i = n - 1; i >= 0; i--)
    {
        ans[i] = max(0ll, (mx + 1) - h[i]);
        mx = max(mx, h[i]);
    }
    for (lol i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}