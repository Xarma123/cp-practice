#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
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
        if (n % 2 == 0)
        {
            cout << 2 << '\n';
            cout << 1 << " " << n << '\n';
            cout << 1 << " " << n << '\n';
        }
        else
        {
            cout << 4 << '\n';
            cout << 1 << " " << n << '\n';
            cout << 1 << " " << 2 << '\n';
            cout << 2 << " " << n << '\n';
            cout << 1 << " " << n << '\n';
        }
    }
}