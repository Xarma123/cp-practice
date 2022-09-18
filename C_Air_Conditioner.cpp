#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol n, m;
        cin >> n >> m;
        bool ans = true;
        lol l = m, r = m, tp = 0;
        while (n--)
        {
            lol ti, li, hi;
            cin >> ti >> li >> hi;
            if (ans)
            {
                l -= (ti - tp);
                r += (ti - tp);
                l = max(l, li);
                r = min(r, hi);
                if (l > r)
                    ans = false;
                tp=ti;
            }
        }
        if (ans)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}