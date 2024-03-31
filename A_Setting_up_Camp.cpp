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
        lol a, b, c;
        cin >> a >> b >> c;
        if (c == 0)
        {
            if (b % 3)
                cout << -1 << '\n';
            else
                cout << (a + (b / 3)) << '\n';
        }
        else if (c == 1)
        {
            if (b % 3 == 2)
            {
                cout << (a + ((b - 2) / 3) + 1) << '\n';
            }
            else if (b % 3 == 0)
            {
                cout << (a + (b / 3) + 1) << '\n';
            }
            else
                cout << -1 << '\n';
        }
        else
        {
            cout << (a + ((b + c + 2) / 3)) << '\n';
        }
    }

    return 0;
}
