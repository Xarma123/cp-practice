#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, x;
    cin >> n >> x;
    lol a[n];
    map<lol, lol> mp;
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
        mp[a[i]]++;
    }
    bool ans = false;
    for (lol i = 0; i < n; i++)
    {

        if (mp.count(a[i] - x))
            ans = true;
    }
    if (ans)
        cout << "Yes";
    else
        cout << "No";

    return 0;
}