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
        lol o = 0;
        lol mn = LONG_LONG_MAX;
        lol mn2 = LONG_LONG_MAX;
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
            if (a[i] % 2)
            {
                o++;
                lol c = 0;
                while (a[i] % 2)
                {
                    a[i] /= 2;
                    c++;
                }
                mn = min(mn, c);
            }
            else
            {
                lol c = 0;
                while (a[i] % 2 == 0)
                {
                    a[i] /= 2;
                    c++;
                }
                mn2 = min(mn2, c);
            }
        }
        if (o % 2)
        {
            cout << min(mn, mn2) << endl;
        }
        else
            cout << 0 << endl;
    }

    return 0;
}