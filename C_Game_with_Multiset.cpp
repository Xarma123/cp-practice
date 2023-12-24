#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol m;
    cin >> m;
    lol set[40];
    memset(set, 0, sizeof(set));
    while (m--)
    {
        lol t, v;
        cin >> t >> v;
        if (t == 1ll)
        {
            set[v]++;
        }
        else
        {
            lol nset[40];
            for (lol i = 0; i < 40; i++)
            {
                nset[i] = set[i];
            }
            bool f = true;
            for (lol i = 0; i < 40 && f; i++)
            {
                if ((v & (1ll << i)))
                {
                    if (nset[i] == 0)
                    {
                        f = false;
                        continue;
                    }
                    else
                    {
                        nset[i]--;
                    }
                }
                if (i < 40)
                {
                    nset[i + 1] += nset[i] / 2ll;
                }
            }
            if (!f)
            {
                cout << "NO\n";
            }
            else
            {
                cout << "YES\n";
            }
        }
    }

    return 0;
}
