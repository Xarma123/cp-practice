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
    lol s = 0;
    lol e = n * 1ll * m + 1;
    while (s != e - 1)
    {
        lol md = (s + e) / 2;

        if (md == 0)
        {
            s = md;
        }
        else if (md == n * 1ll * m + 1)
            e = md;
        else
        {
            lol c = 0;
            for (lol i = 1; i <= n; i++)
            {

                lol x = md / i;
                if (x <= m)
                {
                    c += x;
                }
                else
                    c += m;
            }
            if (c >= k)
                e = md;
            else
                s = md;
        }
    }
    cout << e << endl;

    return 0;
}