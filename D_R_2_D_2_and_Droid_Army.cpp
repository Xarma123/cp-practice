#include <bits/stdc++.h>
#define lol long long
using namespace std;
vector<lol> cmp(vector<lol> &a, vector<lol> &b)
{
    vector<lol> c;
    for (lol i = 0; i < a.size(); i++)
    {
        c.push_back(max(a[i], b[i]));
    }
    return c;
}
lol sum(vector<lol> &a)
{
    lol c = 0;
    for (lol i = 0; i < a.size(); i++)
    {
        c += a[i];
    }
    return c;
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, m, k;
    cin >> n >> m >> k;
    vector<vector<lol>> a;
    for (lol i = 0; i < n; i++)
    {
        vector<lol> y;
        for (lol j = 0; j < m; j++)
        {
            lol t;
            cin >> t;
            y.push_back(t);
        }
        a.push_back(y);
    }
    lol mxn;
    if (n > 1)
        mxn = ceil(log2l(n));
    else
        mxn = 1;

    vector<lol> sparseTable[n][mxn + 1];
    for (lol j = 0; j <= mxn; j++)
    {
        for (lol i = 0; i + (1 << j) - 1 < n; i++)
        {
            if (j == 0)
            {
                sparseTable[i][j] = a[i];
            }
            else
            {
                sparseTable[i][j] = cmp(sparseTable[i][j - 1], sparseTable[i + (1 << (j - 1))][j - 1]);
            }
        }
    }
    lol s = 0;
    lol e = n + 1;

    while (s != e - 1)
    {
        lol md = (s + e) / 2;

        if (md == 0)
            s = 0;
        else if (md == n + 1)
            e = n + 1;
        else
        {

            lol i;
            for (i = 0; i + md - 1 < n; i++)
            {
                vector<lol> y;
                lol j = i + md - 1;
                lol x = log2l(j - i + 1);
                y = cmp(sparseTable[i][x], sparseTable[j + 1 - (1 << x)][x]);

                if (sum(y) <= k)
                    break;
            }
            if (i == n - md + 1)
                e = md;
            else
            {
                s = md;
            }
        }
    }
    if (s == 0)
    {
        cout << k << " ";
        m--;
        while (m--)
        {
            cout << 0 << " ";
        }
    }
    else
    {
        vector<lol> y;
        for (lol i = 0; i + s - 1 < n; i++)
        {
            lol j = i + s - 1;
            lol x = log2l(j - i + 1);
            y = cmp(sparseTable[i][x], sparseTable[j + 1 - (1 << x)][x]);
            if (sum(y) <= k)
                break;
        }
        for (lol i = 0; i < y.size(); i++)
        {
            cout << y[i] << " ";
        }
    }

    return 0;
}