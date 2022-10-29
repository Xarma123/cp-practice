#include <bits/stdc++.h>
#define lol long long
using namespace std;
lol solve(string a[], lol n)
{
    if (n % 2)
        return n;
    for (lol i = 0; i < n / 2; i++)
    {
        if (a[i] != a[n - i - 1])
        {
            return n;
        }
    }
    return solve(a, n / 2);
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, m;
    cin >> n >> m;
    lol a1[n][m];
    for (lol i = 0; i < n; i++)
    {
        for (lol j = 0; j < m; j++)
        {
            cin >> a1[i][j];
        }
    }

    string a[n];
    for (lol i = 0; i < n; i++)
    {
        a[i] = "";
        for (lol j = 0; j < m; j++)
        {
            a[i].push_back(char('0' + a1[i][j]));
        }
    }
    cout << solve(a, n);

    return 0;
}