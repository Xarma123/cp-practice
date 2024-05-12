#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol t;
    cin >> t;
    while (t--)
    {
        lol a, b, c, d;
        cin >> a >> b >> c >> d;
        if ((a % 2) == (b % 2))
        {
            if (a % 2 == 0)
            {
                cout << ((a + b + c) / 2ll) + (d / 2ll);
            }
            else
            {
                cout << ((a + b + c - 2) / 2ll) + (c % 2) + (d / 2ll);
            }
        }
        else
        {
            cout << ((a + b + c - 1) / 2ll) + (d / 2ll);
        }
        cout << '\n';
    }

    return 0;
}
