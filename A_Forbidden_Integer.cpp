#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol n, k, x;
        cin >> n >> k >> x;
        if (x != 1)
        {
            cout << "YES\n";
            cout << n << '\n';
            for (lol i = 0; i < n; i++)
            {
                cout << 1 << " ";
            }
            cout << '\n';
        }
        else if (k == 1)
        {
            cout << "NO\n";
        }
        else if (n % 2 == 0)
        {
            cout << "YES\n";
            cout << n / 2 << '\n';
            for (lol i = 0; i < n / 2; i++)
            {
                cout << 2 << " ";
            }
            cout << '\n';
        }
        else if (k <= 2)
        {
            cout << "NO\n";
        }
        else if (n < 3)
        {
            cout << "NO\n";
        }
        else
        {
            cout << "YES\n";
            cout << 1 + ((n - 3) / 2) << '\n';
            for (lol i = 0; i < ((n - 3) / 2); i++)
            {
                cout << 2 << ' ';
            }
            cout << 3 << '\n';
        }
    }
}