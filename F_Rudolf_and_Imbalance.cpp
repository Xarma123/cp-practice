#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, m;
    cin >> n >> m;
    vector<vector<lol>> a;
    for (lol i = 0; i < n; i++)
    {
        vector<lol> b;
        bool f = false;
        for (lol j = 0; j < m; j++)
        {
            lol v;
            cin >> v;
            b.push_back(v);
        }
        a.push_back(b);
    }
    lol jmin = m, jmax = -1;
    lol imin = n, imax = -1;
    for (lol i = 0; i < n; i++)
    {
        for (lol j = 0; j < m; j++)
        {
            if (a[i][j])
            {
                jmin = min(jmin, j);
                jmax = max(jmax, j);
                imin = min(imin, i);
                imax = max(imax, i);
            }
        }
    }
    lol ans = (jmax - jmin) * 1ll * (imax - imin);
    
    cout << ans;

    return 0;
}
