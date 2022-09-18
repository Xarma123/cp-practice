#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol p, q, l, r;
    cin >> p >> q >> l >> r;
    pair<lol, lol> pn[p];
    pair<lol, lol> qn[q];
    for (lol i = 0; i < p; i++)
    {
        cin >> pn[i].first >> pn[i].second;
    }
    sort(pn, pn + p);
    for (lol i = 0; i < q; i++)
    {
        cin >> qn[i].first >> qn[i].second;
    }
    sort(qn, qn + q);
    lol ans = 0;
    for (lol i = l; i <= r; i++)
    {

        lol x = 0;
        lol z = 0;
        bool f = false;
        while (!f && x < q && z < p)
        {
            if (qn[x].second + i < pn[z].first)
            {
                x++;
            }
            else if (qn[x].first + i > pn[z].second)
            {
                z++;
            }
            else
            {
                f = true;
            }
        }
        if (f)
            ans++;
    }
    cout << ans;

    return 0;
}