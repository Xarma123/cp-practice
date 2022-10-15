#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n;
    cin >> n;
    map<lol, lol> v;
    lol f = 1;
    lol i;
    for (i = 0; i < 2 * 1ll * n; i++)
    {
        if (v.count(((i + n) % (2 * 1ll * n))))
        {
            if (v[(i + n) % (2 * 1ll * n)] == f)
            {
                break;
            }
        }
        v[i] = f;
        f = 1 - f;
    }
    if (i < 2 * 1ll * n)
        cout << "NO";
    else
    {
        cout << "YES" << endl;
        lol a[2 * 1ll * n];
        memset(a, -1, sizeof(a));
        lol q = 2;
        for (lol i = 0; i < 2 * 1ll * n; i++)
        {
            if (a[i] == -1)
            {
                if (v[i])
                {
                    a[i] = q - 1;
                    a[((i + n) % (2 * 1ll * n))] = q;
                    q += 2;
                }
                else
                {
                    a[i] = q;
                    a[((i + n) % (2 * 1ll * n))] = q - 1;
                    q += 2;
                }
            }
        }
        for (lol i = 0; i < 2 * 1ll * n; i++)
            cout << a[i] << " ";
    }

    return 0;
}