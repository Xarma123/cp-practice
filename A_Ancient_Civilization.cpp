#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol n, l;
        cin >> n >> l;
        lol a[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        lol y = a[0];
        for (lol i = 1; i < n; i++)
        {
            y = y & a[i];
        }
        cout << y << endl;
    }

    return 0;
}

