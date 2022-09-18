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
    lol s = 0;
    lol ans = 0;
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] == -1 && s == 0)
            ans++;
        s += a[i];
        if (s <= 0)
            s = 0;
    }
    cout << ans;

    return 0;
}