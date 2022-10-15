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
    lol a[n];
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    lol ans = n;
    for (lol i = 0; i < n; i++)
    {
        lol j = i + 1;
        while (j < n && a[j] == a[i])
            j++;
        ans += (j - i) * 1ll * (j - i - 1) / 2;
        i = j - 1;
    }
    cout << ans;

    return 0;
}