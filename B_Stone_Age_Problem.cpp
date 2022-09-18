#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, q;
    cin >> n >> q;
    lol common = LONG_LONG_MAX;
    map<lol, lol> ind;
    lol sum = 0;
    for (lol i = 0; i < n; i++)
    {
        lol t;
        cin >> t;
        ind[i] = t;
        sum += t;
    }
    while (q--)
    {
        lol t;
        cin >> t;
        if (t == 1)
        {
            lol i, x;
            cin >> i >> x;
            i--;
            if (ind.count(i))
            {
                sum -= ind[i];
                ind[i] = x;
                sum += ind[i];
            }
            else
            {
                sum -= common;
                sum += x;
                ind[i] = x;
            }
            cout << sum << endl;
        }
        else
        {
            lol x;
            cin >> x;
            ind.clear();
            common = x;
            sum = x * 1ll * n;
            cout << sum << endl;
        }
    }

    return 0;
}