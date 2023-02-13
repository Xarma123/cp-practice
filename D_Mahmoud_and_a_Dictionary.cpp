#include <bits/stdc++.h>
#define lol long long
using namespace std;
class dsu
{
public:
    lol n;
    vector<lol> parent;
    dsu(lol _n)
    {
        n = _n;
        parent.assign(2ll * n, 0);
        for (lol i = 0; i < 2ll * n; i++)
        {
            parent[i] = i;
        }
    }
    void unio(lol a, lol b)
    {
        a = find(a);
        b = find(b);
        parent[a] = b;
    }
    lol find(lol a)
    {
        if (parent[a] == a)
            return a;
        return parent[a] = find(parent[a]);
    }
    bool check_friend(lol a, lol b)
    {
        return (find(a) == find(b));
    }
    bool check_enemy(lol a, lol b)
    {
        return (find(a) == find(b + n) || find(b) == find(a + n));
    }
    bool make_friend(lol a, lol b)
    {
        if (!check_enemy(a, b))
        {
            unio(a, b);
            unio(find(a + n), find(b + n));
            return true;
        }
        return false;
    }
    bool make_enemy(lol a, lol b)
    {
        if (!check_friend(a, b))
        {
            unio(find(a), find(b + n));
            unio(find(a + n), find(b));
            return true;
        }
        return false;
    }
};
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, m, q;
    map<string, lol> ind;
    cin >> n >> m >> q;
    for (lol i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        ind[s] = i;
    }
    dsu s(n);
    while (m--)
    {
        lol t;
        cin >> t;
        string a, b;
        cin >> a >> b;
        if (t == 1)
        {
            if (s.make_friend(ind[a], ind[b]))
                cout << "YES" << '\n';
            else
                cout << "NO" << '\n';
        }
        else
        {
            if (s.make_enemy(ind[a], ind[b]))
                cout << "YES" << '\n';
            else
                cout << "NO" << '\n';
        }
    }
    while (q--)
    {
        string a, b;
        cin >> a >> b;
        if (s.check_friend(ind[a], ind[b]))
            cout << 1 << '\n';
        else if (s.check_enemy(ind[a], ind[b]))
            cout << 2 << '\n';
        else
            cout << 3 << '\n';
    }

    return 0;
}