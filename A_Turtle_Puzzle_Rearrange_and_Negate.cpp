#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    ios_base::sync_with_stdio(false);
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
            a[i] %= 3;

            s += a[i];
            s %= 3;
        }
        if (s % 3 == 0)
            cout << 0 << '\n';
        else
        {
            lol i;
            for (i = 0; i < n; i++)
            {
                if (a[i] == s)
                {
                    cout << 1 << '\n';
                    break;
                }
            }
            if (i == n)
            {
                if (s == 2 || s == -1)
                {
                    cout << 1 << '\n';
                }
                else
                {
                    cout << 2 << '\n';
                }
            }
        }
    }

    return 0;
}
