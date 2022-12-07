#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, m, k;
    cin >> n >> m >> k;
    set<lol> h;
    for (lol i = 0; i < m; i++)
    {
        lol q;
        cin >> q;
        h.insert(q);
    }
    lol c = 1;
    bool s = true;
    if (h.count(c))
        s = false;
    while (k--)
    {
        lol a, b;
        cin >> a >> b;
        if (s)
        {
            if (a == c)
            {
                c = b;
            }
            else if (b == c)
            {
                c = a;
            }
            if (h.count(c))
                s = false;
        }
    }
    cout << c;

    return 0;
}