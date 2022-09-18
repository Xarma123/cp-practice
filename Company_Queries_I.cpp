#include <bits/stdc++.h>
#define lol long long
using namespace std;
vector<lol> tree[200001];
vector<lol> Blift[200001];
void dfs(lol x, lol p)
{
    if (p != 0)
        Blift[x].push_back(p);
    lol jump = 1;
    while (Blift[x].size())
    {
        if (Blift[Blift[x].back()].size() >= jump)
        {
            Blift[x].push_back(Blift[Blift[x].back()][jump - 1]);
        }
        else
            break;
        jump++;
    }

    for (lol i = 0; i < tree[x].size(); i++)
    {
        if (tree[x][i] != p)
        {
            dfs(tree[x][i], x);
        }
    }
}
int main()
{
    lol n, q;
    cin >> n >> q;
    for (lol i = 2; i <= n; i++)
    {
        lol a;
        cin >> a;
        tree[a].push_back(i);
        tree[i].push_back(a);
    }

    dfs(1, 0);
    while (q--)
    {
        lol x, k;
        cin >> x >> k;
        lol cnode = x;
        lol i;
        for (i = 0; i < 32; i++)
        {

            if (k & (1 << i))
            {
                if (Blift[cnode].size() >= i + 1)
                {
                    cnode = Blift[cnode][i];
                }
                else
                {
                    break;
                }
            }
        }

        if (i == 32)
            cout << cnode << endl;
        else
            cout << -1 << endl;
    }

    return 0;
}