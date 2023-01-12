#include <bits/stdc++.h>
#define lol long long
using namespace std;
lol f(lol a, lol i)
{
    return (a & (1ll << i));
}
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
        lol j;
        for (j = 31; j >= 0; j--)
        {
            lol o = 0, z = 0;
            for (lol i = 0; i < n; i++)
            {
                if (f(a[i], j))
                    o++;
                else
                    z++;
            }
           
            if (!(z % 2 == 0 || o % 2 == 0 || z == n || o == n))
                break;
        }
        if (j >= 0)
            cout << "NO" << '\n';
        else
            cout << "YES" << '\n';
    }

    return 0;
}