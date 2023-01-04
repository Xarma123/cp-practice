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
        lol n, s, k;
        cin >> n >> k >> s;
        if (k == 1)
        {
            if (s <= n)
            {
                for (lol i = 0; i < n; i++)
                {
                    if (i < s)
                        cout << 1 << " ";
                    else
                        cout << 0 << " ";
                }
                cout << endl;
            }
            else
                cout << -2 << endl;
        }
        else
        {
            lol b[n];
            memset(b, 0, sizeof(b));
            lol p, v;
            bool f = true;
            while (s)
            {
                p = 0;
                v = 1;
                while (v <= s)
                {
                    v = v * 1ll * k;
                    p++;
                }
                p--;
                if (p >= n)
                {
                    f = false;
                    break;
                }
                b[p]++;
                s -= powl(k, p);
            }

            for (lol i = 0; i < n; i++)
            {
                if (b[i] > 1)
                    f = false;
            }
            if (f)
            {
                for (lol i = 0; i < n; i++)
                {
                    cout << b[i] << " ";
                }
                cout << endl;
            }
            else
                cout << -2 << endl;
        }
    }

    return 0;
}