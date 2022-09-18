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
        lol n, q;
        cin >> n >> q;
        lol a[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        sort(a, a + n);
        vector<lol> c;

        c.push_back(0);
        for (lol i = 1; i <= n; i++)
        {
            c.push_back(a[i - 1] + c[i - 1]);
        }
        while (q--)
        {
            lol x;
            cin >> x;
            lol s = 0;
            lol e = c.size();
            while (s != e - 1)
            {
                lol m = (s + e) / 2;
                if (m == 0)
                    s = m;
                else if (m == c.size())
                    e = m;
                else if (c[c.size() - 1] - c[m - 1] >= x)
                    s = m;
                else
                    e = m;
            }
            if (s == 0)
                cout << -1 << endl;
            else
            {
                cout << c.size() - s<<endl;

            }
        }
    }

    return 0;
}