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
        if (a[0] < a[n - 1])
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}