#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{

    lol t;
    cin >> t;
    while (t--)
    {
        lol n;
        cin >> n;
        if (n <= 2)
        {
            for (lol i = 1; i <= n; i++)
            {
                cout << i << " ";
            }
            cout << '\n';
        }
        else
        {
            cout << 2 << " ";
            for (lol i = 4; i < 4 + ((n - 3) / 2); i++)
            {
                cout << i << " ";
            }
            cout << 1 << " ";
            for (lol i = 4 + ((n - 3) / 2); i < 4 + ((n - 3) / 2) + ((n - 2) / 2); i++)
            {
                cout << i << ' ';
            }
            cout << 3;
            cout << '\n';
        }
    }
}