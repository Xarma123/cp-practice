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
        bool oz = false, zz = false;
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
            s += a[i];
            if (i)
            {
                if (a[i] == a[i - 1])
                {
                    if (a[i] == -1)
                        zz = true;
                }
                else
                    oz = true;
            }
        }
        if (zz)
        {
            s += 4;
        }
        else if (!oz)
        {
            s -= 4;
        }
        cout << s << '\n';
    }

    return 0;
}