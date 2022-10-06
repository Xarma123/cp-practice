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
        lol c[n];
        lol mx = 0;
        for (lol i = 0; i < n; i++)
        {
            cin >> c[i];
            if (c[i] > c[mx])
            {
                mx = i;
            }
        }
        if (mx == 0)
            cout << -1 << endl;
        else
        {
            cout << mx << endl;
            for (lol i = 0; i < mx; i++)
            {
                cout << c[i] << " ";
            }
            cout << endl;
            cout << n - mx << endl;
            for (lol i = mx; i < n; i++)
            {
                cout << c[i] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}