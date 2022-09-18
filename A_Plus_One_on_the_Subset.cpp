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
        lol mn = INT_MAX;
        lol mx = INT_MIN;
        while (n--)
        {
            lol q;
            cin >> q;
            mn = min(mn, q);
            mx = max(mx, q);
        }
        cout << mx - mn << endl;
    }

    return 0;
}