#include <bits/stdc++.h>
using namespace std;
#define lol long long

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol t;
    cin >> t;
    while (t--)
    {
       
        lol n, m;
        cin >> n >> m;
        lol a[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        lol p[m];

        for (lol i = 0; i < m; i++)
        {
            cin >> p[i];
            p[i]--;
        }
        sort(p, p + m);

        for (lol i = 0; i < m; i++)
        {
            lol j = i + 1;
            while (j < m && p[j - 1] == p[j] - 1)
            {
                j++;
            }
            sort(a + p[i], a + p[j - 1] + 2);
        }
        if (is_sorted(a, a + n))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}