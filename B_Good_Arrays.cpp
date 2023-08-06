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
        lol s = 0;
        lol c = 0;
        lol mx = 0;
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
            s += a[i];
            if (a[i] == 1)
                c++;
            mx = max(mx, a[i]);
        }
        if (n == 1)
        {
            cout << "NO\n";
        }
        else
        {
            lol v = s - (n - 1) - c;
            if (v > 0)
            {
                cout << "YES\n";
            }
            else
                cout << "NO\n";
        }
    }
}