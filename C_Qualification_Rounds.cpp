#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{

    lol n, k;
    cin >> n >> k;
    set<lol> x;
    bool ans = false;
    if (n == 1)
    {   ans=true;
        for (lol i = 0; i < k; i++)
        {
            lol t;
            cin >> t;

            if (t)
            {
                ans = false;
            }
        }
    }
    else
    {
        while (n--)
        {
            lol g = 0;
            for (lol i = 0; i < k; i++)
            {
                lol t;
                cin >> t;
                if (k == 1)
                {
                    if (t == 0)
                        ans = true;
                }
                if (t)
                {
                    g = g | (1 << i);
                }
            }

            for (lol i = 0; i < pow(2, k); i++)
            {
                if ((i & g) == 0)
                {

                    if (x.count(i))
                        ans = true;
                }
            }

            x.insert(g);
        }
    }
    if (ans)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}