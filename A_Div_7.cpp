#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol T;
    cin >> T;
    while (T--)
    {
        lol n;
        cin >> n;
        if (n % 7 == 0)
            cout << n << endl;
        else
        {
            lol r = n % 7;
            lol l = n % 10;
            if (l + (7 - r) < 10)
            {
                cout << n + (7 - r) << endl;
            }
            else
            {
                cout << n - r << endl;
            }
        }
    }

    return 0;
}