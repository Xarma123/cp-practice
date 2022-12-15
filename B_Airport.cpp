#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, m;
    cin >> n >> m;
    multiset<lol> x, x2;
    for (lol i = 0; i < m; i++)
    {
        lol q;
        cin >> q;
        x.insert(q);
        x2.insert(-q);
    }
    lol mn = 0;
    lol N = n;
    while (N--)
    {
        lol v = (*x.begin());
        x.erase(x.begin());
        mn += v;
        v--;
        if (v)
            x.insert(v);
    }
    lol mx = 0;
    N = n;
    while (N--)
    {
        lol v = (*x2.begin());
        x2.erase(x2.begin());
        mx += -v;
        v++;
        if (v != 0)
            x2.insert(v);
    }
    cout << mx << " " << mn;

    return 0;
}