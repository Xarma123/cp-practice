#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol t;
    cin >> t;
    while (t--)
    {
        lol n, k;
        cin >> n >> k;
        lol a[n];
        set<lol> x;
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
            x.insert(a[i]);
        }
        if (k == 0)
        {
            cout << n << '\n';
            continue;
        }
        lol mex = -1;
        for (lol i = 0; i < n; i++)
        {
            if (!x.count(i))
            {
                mex = i;
                break;
            }
        }
        if (mex == -1)
            mex = n;
        lol mx = (*x.rbegin());
        if (mex < mx)
        {
            x.insert((long long)ceill((mex + mx) / (long double)2));
            cout << x.size() << '\n';
        }
        else
        {
            cout << x.size() + k << '\n';
        }
    }
}