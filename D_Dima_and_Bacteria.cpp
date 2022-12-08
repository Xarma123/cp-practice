#include <bits/stdc++.h>
#define lol long long
using namespace std;
lol sz[100005];
lol parent[100005];
lol find(lol a)
{
    if (parent[a] == a)
        return a;
    return parent[a] = find(parent[a]);
}
lol unio(lol a, lol b)
{
    lol a1 = find(a);
    lol a2 = find(b);
    if (a1 != a2)
    {
        if (sz[a1] <= sz[a2])
        {
            sz[a2] += sz[a1];
            parent[a1] = a2;
        }
        else
        {
            sz[a1] += sz[a2];
            parent[a2] = a1;
        }
    }
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, m, k;
    cin >> n >> m >> k;
    lol c[k];
    for (lol i = 0; i < k; i++)
    {
        cin >> c[i];
    }
    lol a[n];
    lol v = 0;
    lol j = 1;
    for (lol i = 0; i < n; i++)
    {
        if (i + 1 <= v + c[j - 1])
        {
            a[i] = j;
        }
        else
        {
            v += c[j - 1];
            j++;
            a[i] = j;
        }
    }

    lol d[k][k];
    for (lol i = 0; i < k; i++)
    {
        for (lol j = 0; j < k; j++)
        {
            d[i][j] = 1e12;
        }
        d[i][i] = 0;
    }

    for (lol i = 0; i < n; i++)
    {
        parent[i] = i;
    }

    for (lol i = 0; i < n; i++)
    {
        sz[i] = 1;
    }

    while (m--)
    {
        lol u, v, x;
        cin >> u >> v >> x;
        d[a[u - 1] - 1][a[v - 1] - 1] = min(d[a[u - 1] - 1][a[v - 1] - 1], x);
        d[a[v - 1] - 1][a[u - 1] - 1] = min(d[a[v - 1] - 1][a[u - 1] - 1], x);
        if (x == 0)
        {
            unio(u - 1, v - 1);
        }
    }
    bool f = true;

    for (lol i = 0; i < n; i++)
    {
        lol j = i + 1;
        while (j < n && a[j] == a[i])
            j++;
        lol q = find(i);
        for (lol k1 = i; k1 < j; k1++)
        {
            if (find(k1) != q)
                f = false;
        }
        i = j - 1;
    }
    if (!f)
        cout << "No";
    else
    {
        cout << "Yes" << endl;
        for (lol i = 0; i < k; i++)
        {
            for (lol j = 0; j < k; j++)
            {
                for (lol k1 = 0; k1 < k; k1++)
                {
                    d[j][k1] = min(d[j][k1], d[j][i] + d[i][k1]);
                }
            }
        }
        for (lol i = 0; i < k; i++)
        {
            for (lol j = 0; j < k; j++)
            {
                if (d[i][j] == 1e12)
                    d[i][j] = -1;
                cout << d[i][j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}