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
    lol c = 1;
    while (t--)
    {
        lol m, n, p;
        cin >> m >> n >> p;
        lol mx[n];
        for (lol i = 0; i < n; i++)
        {
            mx[i] = LONG_LONG_MIN;
        }

        lol a[n];
        for (lol i = 0; i < m; i++)
        {
            for (lol j = 0; j < n; j++)
            {
                lol q;
                cin >> q;
                mx[j] = max(mx[j], q);
                if (i == p - 1)
                    a[j] = q;
            }
        }
        lol ex = 0;
        for (lol i = 0; i < n; i++)
        {
         
            ex += max((mx[i] - (a[i])), 0ll);
        }
        cout << "Case #" << c << ": " << ex << endl;
        c++;
    }

    return 0;
}