#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol n;
        cin >> n;
        n *= 2;
        multiset<lol> m;
        multiset<lol> d;
        long double ans = 0;
        while (n--)
        {
            lol x, y;
            cin >> x >> y;
            if (x == 0)
            {
                if (y < 0)
                    y = -y;
                m.insert(y);
            }
            else
            {
                if (x < 0)
                    x = -x;
                d.insert(x);
            }
        }
        auto it = m.begin();
        auto it1 = d.begin();
        while (it != m.end() && it1 != d.end())
        {
            ans += sqrtl((*it) * (*it) + (*it1) * (*it1));
            it++;
            it1++;
        }
        cout<<setprecision(12)<<ans<<endl;
    }

    return 0;
}