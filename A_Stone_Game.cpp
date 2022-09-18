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
        lol mn = -1;
        lol mx = -1;

        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
            if (a[i] == 1)
                mn = i;
            if (a[i] == n)
                mx = i;
        }
        if (mn > mx)
            swap(mn, mx);
        cout << min(mn + (n - mx) + 1, min(mx + 1, n - mn)) << endl;
    }

    return 0;
}