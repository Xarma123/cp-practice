#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol t;
    cin >> t;
    while (t--)
    {
        lol a, b, l;
        cin >> a >> b >> l;
        set<lol> x;
        lol v1 = 1;
        for (lol i = 0; v1 <= l; i++)
        {
            lol v2 = 1;
            for (lol j = 0; v2 <= l; j++)
            {
                lol v = v1 * 1ll * v2;

                if (l % v == 0)
                    x.insert(l / v);
                v2 = v2 * 1ll * b;
            }
            v1 = v1 * 1ll * a;
        }
        cout << x.size() << '\n';
    }

    return 0;
}
