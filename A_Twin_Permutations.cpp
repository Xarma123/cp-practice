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
        lol a[n];

        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
            cout << n - a[i] + 1 << " ";
        }
        cout << '\n';
    }
}