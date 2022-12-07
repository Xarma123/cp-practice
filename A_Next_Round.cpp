#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, k;
    cin >> n >> k;
    lol a[n];
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    lol ans = 0;
    for (lol i = 0; i < n; i++)
    {
        if (a[i] >= max(1ll, a[k - 1]))
            ans++;
    }
    cout << ans;

    return 0;
}