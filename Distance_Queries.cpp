#include <bits/stdc++.h>
#define lol long long
using namespace std;
vector<lol> tree[200001];
vector<lol> Blift[200001];
lol level[200001];
void dfs(lol x, lol p, lol d)
{
    level[x] = d;
    if (p != 0)
        Blift[x].push_back(p);
    lol jump = 1;
    while (Blift[x].size())
    {
        if (Blift[Blift[x].back()].size() >= jump)
        {
            Blift[x].push_back(Blift[Blift[x].back()][jump - 1]);
            if (Blift[x].back() == -1)
            {
                Blift[x].pop_back();
                break;
            }
        }
        else
            break;
        jump++;
    }

    for (lol i = 0; i < tree[x].size(); i++)
    {
        if (tree[x][i] != p)
        {
            dfs(tree[x][i], x, d + 1);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    lol n, q;
    cin >> n >> q;
    for (lol i = 0; i < n - 1; i++)
    {
        lol a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    dfs(1, 0, 0);
    while (q--)
    {
        lol A, B;
        lol a, b;
        cin >> a >> b;
        if (level[a] < level[b])
            swap(a, b);
        A = a;
        B = b;
        if (level[a] > level[b])
        {
            lol cnode = a;
            lol i;
            for (i = 0; i < 32; i++)
            {

                if ((level[a] - level[b]) & (1 << i))
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

            a = cnode;
        }
        while (1)
        {
            lol j = Blift[a].size();
            if (j == 0)
                break;
            while (Blift[a][j - 1] == Blift[b][j - 1])
            {
                j--;
                if (j < 1)
                    break;
            }

            if (j == 0)
                break;
            a = Blift[a][j - 1];
            b = Blift[b][j - 1];
        }
        if (a == b)
            cout << level[A] + level[B] - level[a] - level[a] << '\n';
        else
            cout << level[A] + level[B] - level[Blift[a][0]] - level[Blift[a][0]] << '\n';
    }

    return 0;
}