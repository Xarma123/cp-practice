#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol n, k;
        cin >> n >> k;
        lol a[n];
        set<lol> x;
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
            x.insert(a[i]);
        }
        if (x.size() <= k)
        {
            cout << 1 << endl;
        }
        else
        {
            lol c = x.size() - k;
            if (k - 1 == 0)
            {
                cout << -1 << endl;
            }
            else
            {

                cout << 1 + ceil(c / (long double)(k - 1)) << endl;
            }
        }
    }

    return 0;
}