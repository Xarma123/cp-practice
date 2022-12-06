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
        vector<lol> a[2 * 1ll * n - 1];
        lol ap = 0, ora = 0;
        for (lol i = 0; i < 2 * 1ll * n - 1; i++)
        {
            lol a1, b1, c;
            cin >> a1 >> b1;
            c = i;
            ap += a1;
            ora += b1;
            a[i].push_back(a1);
            a[i].push_back(b1);
            a[i].push_back(c);
        }
        sort(a, a + 2 * 1ll * n-1);
        ap = ceill(ap / (long double)2);
        ora = ceill(ora / (long double)2);
        lol sa = a[2 * 1ll * n - 2][0];
        lol so = a[2 * 1ll * n - 2][1];

        for (lol i = 0; i < 2 * 1ll * n - 2; i += 2)
        {
            sa += a[i][0];
            so += a[i][1];
        }
        if (sa >= ap && so >= ora)
        {

            cout << "YES" << endl;
            for (lol i = 0; i < 2 * 1ll * n - 2; i += 2)
                cout << a[i][2] + 1 << " ";
            cout << a[2 * 1ll * n - 2][2] + 1;
            cout << endl;
        }
        else
        {
            sa = a[2 * 1ll * n - 2][0];
            so = a[2 * 1ll * n - 2][1];

            for (lol i = 1; i < 2 * 1ll * n - 2; i += 2)
            {
                sa += a[i][0];
                so += a[i][1];
            }
            if (sa >= ap && so >= ora)
            {

                cout << "YES" << endl;
                for (lol i = 1; i < 2 * 1ll * n - 2; i += 2)
                    cout << a[i][2] + 1 << " ";
                cout << a[2 * 1ll * n - 2][2] + 1;
                cout << endl;
            }
            else
                cout << "NO" << endl;
        }
    }

    return 0;
}