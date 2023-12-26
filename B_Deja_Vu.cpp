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
        lol n, m;
        cin >> n >> m;
        lol a[n];
        lol q[m];
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (lol i = 0; i < m; i++)
        {
            cin >> q[i];
        }

        vector<lol> cmp;
        cmp.push_back(q[0]);
        for (lol i = 1; i < m; i++)
        {
            if (q[i] < cmp.back())
            {
                cmp.push_back(q[i]);
            }
        }
        for (lol i = 0; i < n; i++)
        {
            for (auto e : cmp)
            {
                if (a[i] % (1ll << e) == 0)
                {
                    a[i] += (1ll << (e - 1));
                }
            }
            cout << a[i] << " ";
        }
        cout << '\n';
    }

    return 0;
}
