#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol t;
    cin >> t;
    while (t--)
    {
        lol n, m;
        cin >> n >> m;
        set<lol> r, c;
        while (m--)
        {
            lol x, y;
            cin >> x >> y;
            r.insert(x);
            c.insert(y);
        }
        if (r.size() < n || c.size() < m)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}