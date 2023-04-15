#include <bits/stdc++.h>
#define lol long long
using namespace std;
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
        lol s = 0;
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
            s ^= a[i];
        }
        if (s == 0)
            cout << 0 << '\n';
        else if (n % 2)
            cout << s << '\n';
        else
            cout << -1 << '\n';
    }

    return 0;
}