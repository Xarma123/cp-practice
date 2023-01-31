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
    map<lol, lol> mp;
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (lol i = 0; i < n; i++)
    {
        lol q;
        cin >> q;
        mp[q] = i;
    }
    for (lol i = 0; i < n; i++)
    {
        a[i] = mp[a[i]];
    }
    lol i;
    for (i = 1; i < n; i++)
    {
        if (a[i] < a[i - 1])
            break;
    }
    cout << n - i;

    return 0;
}