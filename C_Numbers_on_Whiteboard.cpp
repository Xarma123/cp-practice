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
        cout << 2 << endl;

        if (n - 2 > 0)
        {
            cout << n << " " << n - 2 << endl;
            cout << n - 1 << " " << n - 1 << endl;
            n--;
            while (n - 2 > 0)
            {
                cout << n << " " << n - 2 << endl;
                n--;
            }
        }
        else
        {
            cout << n << " " << n - 1 << endl;
        }
    }

    return 0;
}