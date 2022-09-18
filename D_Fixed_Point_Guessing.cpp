#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);

    lol t;
    cin >> t;
    while (t--)
    {
        lol n;
        cin >> n;
        lol l = 1;
        lol r = n;
        while (l < r)
        {
            lol m = (l + r) / 2;
            cout << "? " << l << " " << m << endl;
            lol c = 0;
            for (lol i = l; i <= m; i++)
            {
                lol q;
                cin >> q;
                if (q>=l&&q<=m)
                    c++;
            }
            if (c % 2 == 0)
            {
                l = m+1;
            }
            else
            {
                r = m;
            }
        }
        cout << "! " << l << endl;
    }

    return 0;
}