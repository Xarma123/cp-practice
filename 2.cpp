#include <bits/stdc++.h>
using namespace std;
#define lol long long

lol find(lol a, lol p[])
{
    if (p[a] == a)
        return a;
    return p[a] = find(p[a],p);
}
void unio(lol a, lol b, lol p[], lol sz[], lol mx[])
{
    a = find(a, p);
    b = find(b, p);
    if (a != b)
    {
        if (sz[a] <= sz[b])
        {
            p[a] = b;
            sz[b] += sz[a];
            mx[b] = max(mx[b], mx[a]);
        }
        else
        {
            p[b] = a;
            sz[a] += sz[b];
            mx[a] = max(mx[b], mx[a]);
        }
    }
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n;
    cin >> n;
    lol e;
    cin >> e;
    lol p[n + 1];
    for (lol i = 0; i <= n; i++)
    {
        p[i] = i;
    }
    lol sz[n + 1];
    for (lol i = 0; i <= n; i++)
    {
        sz[i] = 1;
    }
    lol mx[n + 1];
    for (lol i = 0; i <= n; i++)
    {
        mx[i] = i;
    }
    lol ans = n * 1ll * (n + 1) / 2;

    while (e--)
    {
        lol a, b;
        cin >> a >> b;
        if (find(a, p) != find(b, p))
        {
            ans -= mx[find(a, p)] + mx[find(b, p)];
            unio(a, b, p, sz, mx);
            ans += mx[find(a, p)];
        }
        cout << ans << '\n';
    }
}