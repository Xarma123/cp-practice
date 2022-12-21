#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol t;
    cin >> t;
    while (t--)
    {
        lol n;
        cin >> n;
        lol a[n];
        lol mx = 0;
        lol mn = -1;
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
            mx |= a[i];
            if (mn == -1)
                mn = a[i];
            else
                mn &= a[i];
        }
        cout << mx - mn << endl;
    }

    return 0;
}