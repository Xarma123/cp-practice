#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol n;
        cin >> n;
        lol a[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
            a[i] = a[i] - i;
        }
        unordered_map<lol, lol> x;
        lol ans = 0;
        for (lol i = 0; i < n; i++)
        {

            ans += x[a[i]];

            x[a[i]]++;
        }
        cout << ans << endl;
    }

    return 0;
}