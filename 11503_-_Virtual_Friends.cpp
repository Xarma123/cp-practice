#include <bits/stdc++.h>
#define lol long long
using namespace std;
map<string, string> parent;
map<string, lol> sz;
string find(string a)
{
    if (!parent.count(a))
        return a;
    return parent[a] = find(parent[a]);
}
lol unio(string a, string b)
{
    string ap = find(a);
    string bp = find(b);
    if (!sz.count(ap))
        sz[ap] = 1;
    if (!sz.count(bp))
        sz[bp] = 1;
    if (ap == bp)
        return sz[ap];
    if (sz[ap] <= sz[bp])
    {
        parent[ap] = bp;
        sz[bp] += sz[ap];
        return sz[bp];
    }
    else
    {
        parent[bp] = ap;
        sz[ap] += sz[bp];
        return sz[ap];
    }
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol t;
    cin >> t;
    while (t--)
    {
        parent.clear();
        sz.clear();
        lol n;
        cin >> n;
        while (n--)
        {
            string a, b;
            cin >> a >> b;
            cout << unio(a, b) << endl;
        }
    }

    return 0;
}