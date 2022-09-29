#include <bits/stdc++.h>
#define lol long long
using namespace std;
lol ncr[61][61];
lol m = 998244353;
map<lol, lol> w;
map<lol, lol> l;
lol loss(lol n);
lol win(lol n)
{
    if (n == 0)
        return 0;
    if (w.count(n))
        return w[n];

    return w[n] = ((ncr[n - 1][n / 2] + loss(n - 2)) % m);
}
lol loss(lol n)
{
    if (l.count(n))
        return l[n];
    if (n == 0)
        return 0; 
    return l[n] = ((ncr[n][n / 2] - win(n) - 1 + m) % m);
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol t;
    cin >> t;

    for (lol i = 0; i < 61; i++)
    {
        for (lol j = 0; j < 61; j++)
        {
            if (i == j)
                ncr[i][j] = 1;
            else if (i < j)
                ncr[i][j] = 0;
            else if (j == 0)
                ncr[i][j] = 1;
            else if (j == 1)
                ncr[i][j] = i;
            else
                ncr[i][j] = (ncr[i - 1][j] + ncr[i - 1][j - 1]) % m;
        }
    }

    while (t--)
    {
        lol n;
        cin >> n;
        cout << win(n) << " " << loss(n) << " " << 1 << endl;
    }

    return 0;
}