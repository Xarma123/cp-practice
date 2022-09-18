#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, h;
    cin >> n >> h;
    lol a[n];
    lol ans = n;
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] > h)
            ans++;
    }
    cout << ans;

    return 0;
}