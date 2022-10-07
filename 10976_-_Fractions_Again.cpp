#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol k;
    while (cin >> k)
    {
        set<lol> q;
        for (lol x = k + 1; x <= 2 * 1ll * k; x++)
        {
            if ((k * 1ll * x) % (x - k) != 0)
                continue;
            else
            {
                q.insert(x);
            }
        }
        cout << q.size() << endl;
        for (auto e : q)
        {
            cout << 1 << "/" << k << " = " << 1 << "/" << (k * 1ll * e) / (e - k) << " + " << 1 << "/" << e << endl;
        }
    }

    return 0;
}