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
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        if (n == 1 || n == 2)
        {
            for (lol i = 0; i < n; i++)
            {
              
                cout << a[i] << " ";
            }
        }
        else if (a[0] == n)
        {
            cout << a[0] << " ";
            for (lol i = n - 1; i > 0; i--)
            {

                cout << a[i] << " ";
            }
        }
        else if (a[n - 1]  == n)
        {
            cout << a[n - 1] << " ";
            for (lol i = n - 2; i >= 0; i--)
            {

                cout << a[i] << " ";
            }
        }
        else
            cout << -1;
        cout << endl;
    }

    return 0;
}