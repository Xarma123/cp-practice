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
        for (lol i = n - 1; i >= 0; i--)
        {
            if (i == n - 1)
                a[i] = 1;
            else
            {
                if (a[i] == 1)
                {
                    a[i] = 1 - a[i + 1];
                }
                else
                {
                    a[i] = 1;
                }
            }
        }
        if (a[0])
            cout << "First" << endl;
        else
            cout << "Second" << endl;
    }

    return 0;
}