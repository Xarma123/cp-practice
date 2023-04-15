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
        lol a[n - 1];
        for (lol i = 0; i < n - 1; i++)
        {
            cin >> a[i];
        }
        lol b[n];
        lol l = 0, r = LONG_LONG_MAX;
        for (lol i = n - 1; i >= 0; i--)
        {
            if (i - 1 >= 0)
            {
                if (a[i - 1] <= r && a[i - 1] >= l)
                {
                    b[i] = a[i - 1];
                    l = 0;
                    r = a[i - 1];
                }
                else
                {
                    b[i] = l;
                    l = a[i - 1];
                    r = a[i - 1];
                }
            }
            else
            {
                b[i] = l;
            }
        }
        for (lol i = 0; i < n; i++)
        {
            cout << b[i] << ' ';
        }
        cout << '\n';
    }

    return 0;
}