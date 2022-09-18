#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, m, k;
    cin >> n >> m >> k;
    lol a[n];
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    sort(a, a + n);
    lol s = a[0];
    lol e = 1e18;
    while (s != e - 1)
    {
        lol md = (s + e) / 2;
        vector<lol> x;
        for (lol i = 0; i < n; i++)
        {
            if ((md & a[i]) == md)
                x.push_back(0);
            else
                x.push_back(md - a[i]);
        }
        sort(x.begin(), x.end());
        lol need = 0;
        for (lol i = 0; i < k; i++)
        {
            need += x[i];
        }
        if (need <= m)
        {
            s = md;
        }
        else
            e = md;
    }
    cout << s;

    return 0;
}