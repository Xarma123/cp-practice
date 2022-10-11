#include <bits/stdc++.h>
#define lol long long
using namespace std;
lol v, z;
lol find(vector<lol> &parent, lol c)
{
    if (parent[c] == -1)
        return c;
    return parent[c] = find(parent, parent[c]);
}
void join(vector<lol> &parent, vector<lol> &rank, lol a, lol b)
{
    if (find(parent, a) == find(parent, b))
    {
        return;
    }
    lol pa = find(parent, a);
    lol pb = find(parent, b);
    if (rank[pa] > rank[pb])
    {
        parent[pb] = pa;
        rank[pa] += rank[pb];
    }
    else
    {
        parent[pa] = pb;
        rank[pb] += rank[pa];
    }
}
lol mnmst(vector<lol> &parent, vector<lol> &rank, vector<vector<lol>> edg, lol av)
{
    for (lol i = 0; i <= v; i++)
    {
        parent[i] = -1;
        rank[i] = 1;
    }

    lol ans = 0;
    lol c = 0;
    for (lol i = 0; i < edg.size(); i++)
    {
        vector<lol> e = edg[i];
        if (i == av)
            continue;
        if (find(parent, e[1]) == find(parent, e[2]))
            continue;
        join(parent, rank, find(parent, e[1]), find(parent, e[2]));
        ans += e[0];
        c++;
    }
    if (c == v - 1)
        return ans;
    else
        return LONG_LONG_MAX;
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol t;
    cin >> t;
    lol cas = 1;
    while (t--)
    {

        cin >> v >> z;
        vector<vector<lol>> edg;
        while (z--)
        {
            lol a, b, c;
            cin >> a >> b >> c;
            edg.push_back({c, a, b});
        }
        sort(edg.begin(), edg.end());
        vector<lol> rank(v + 1, 1);
        vector<lol> parent(v + 1, -1);
        lol c = 0;
        lol ans = 0;
        lol k = -1;
        set<lol> ex;
        for (auto e : edg)
        {
            k++;
            if (find(parent, e[1]) == find(parent, e[2]))
                continue;
            join(parent, rank, find(parent, e[1]), find(parent, e[2]));
            ex.insert(k);

            c++;
            ans += e[0];
        }
        if (c != v - 1)
        {
            cout << "Case #" << cas << " : "
                 << "No way" << endl;
        }
        else
        {

            lol ans1 = LONG_LONG_MAX;
            for (auto i : ex)
            {
                ans1 = min(ans1, mnmst(parent, rank, edg, i));
            }
            if (ans1 == LONG_LONG_MAX)
            {
                cout << "Case #" << cas << " : "
                     << "No second way" << endl;
            }
            else
            {
                cout << "Case #" << cas << " : "
                     << ans1 << endl;
            }
        }

        cas++;
    }

    return 0;
}