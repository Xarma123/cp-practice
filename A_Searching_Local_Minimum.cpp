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
    if (n == 1)
        cout << "! " << 1;
    else
    {
        lol l = 1, r = n;
        while (r - l > 0)
        {
            lol m = (l + r) / 2;
            if (m == n)
            {
                r = m;
            }
            else
            {
                cout << "? " << m << endl;
                lol v;
                cin >> v;
                cout << "? " << m + 1 << endl;
                lol v2;
                cin >> v2;
                if (v2 > v)
                {
                    r = m;
                }
                else
                {
                    l = m + 1;
                }
            }
        }
        cout << "! " << l;
    }

    return 0;
}