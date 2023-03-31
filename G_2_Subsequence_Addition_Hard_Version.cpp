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
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        lol x = 1;
        sort(a, a + n);
        lol i;
        for (i = 0; i < n; i++)
        {
            if (a[i] > x)
            {
                break;
            }
            else if (i)
                x += a[i];
        }
        if (i == n)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}