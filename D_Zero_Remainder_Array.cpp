#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol n, k;
        cin >> n >> k;
        map<lol, lol> x;
        bool f = true;
        for (lol i = 0; i < n; i++)
        {
            lol c;
            cin >> c;
            c = c % k;
            if (c != 0)
                f = false;
            c = k - c;
            if (c != k)
                x[c]++;
        }
        if (f)
            cout << 0 << endl;
        else
        {
            lol ans = 0;
            lol mx = LONG_LONG_MIN;
            lol d = 0;
            for (auto i = x.begin(); i != x.end(); i++)
            {
                if ((*i).second >= mx)
                {
                    mx = (*i).second;
                    d = (*i).first;
                }
            }
            ans += (mx - 1) * k;
            ans += d + 1;
            cout << ans << endl;
        }
    }

    return 0;
}