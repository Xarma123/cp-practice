#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol n, W;
        cin >> n >> W;
        multiset<lol> w;
        for (lol i = 0; i < n; i++)
        {
            lol T;
            cin >> T;
            w.insert(T);
        }
        lol sum = W;
        lol ans = 1;
        while (!w.empty())
        {
            auto i = w.upper_bound(sum);
            if (i != w.begin())
            {
                i--;
                sum -= (*i);
                w.erase(i);
            }
            else
            {
                ans++;
                sum = W;
            }
        }
        cout << ans << endl;
    }

    return 0;
}