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

    lol mn = -a[0];
    lol s = -a[0];
    for (lol i = 1; i < n; i++)
    {
        s += a[i - 1] - a[i];
        mn = min(mn, s);
    }
    if (mn < 0)
        cout << abs(mn);
    else
        cout << 0;

    return 0;
}