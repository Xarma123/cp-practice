#include <bits/stdc++.h>
#define lol long long
using namespace std;
vector<vector<lol>> a;
lol ans(lol r, lol c, vector<vector<lol>> &a)
{
    lol m = a.size();
    lol n = a[0].size();

    if (r == m - 1 && c == n - 1)
    {
        a[r][c] = 1;
        return 1;
    }
    if (a[r][c] == -1)
    {
        lol q = 0;
        if (c + 1 < n)
        {
            if (a[r][c + 1] == -1)
            {
                lol rt = ans(r, c + 1, a);
                a[r][c + 1] = rt;
            }
            q += a[r][c + 1];
        }
        if (r + 1 < m)
        {
            if (a[r + 1][c] == -1)
            {
                lol dt = ans(r + 1, c, a);
                
                a[r + 1][c] = dt;
            }
            q += a[r + 1][c];
        }
        a[r][c] = q;
    }
    return a[r][c];
}
lol uniquePaths(lol m, lol n)
{   a.clear();
    if (n == 1 && m == 1)
        return 0;
    for (lol i = 0; i < m; i++)
    {
        vector<lol> x;
        for (lol i = 0; i < n; i++)
        {

            x.push_back(-1);
        }
        a.push_back(x);
        x.clear();
    }
    return ans(0, 0, a);
}

int main()
{
    cout << uniquePaths(100, 100) << endl;
    return 0;
}