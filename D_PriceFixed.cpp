#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol n;
    cin >> n;
    pair<lol, lol> a[n];
    for (lol i = 0; i < n; i++)
    {
        lol t, b;
        cin >> t >> b;
        a[i] = make_pair(b, t);
    }
    sort(a, a + n);
  
    lol ans = 0, items = 0, e = n - 1;
    for (lol i = 0; i < n; i++)
    {
        if (a[i].second == 0)
            break;
        if (a[i].first <= items)
        {
            ans += a[i].second;
            items += a[i].second;
            a[i].second = 0;
        }
        else
        {
            while (items < a[i].first)
            {  
                if (a[e].second >= a[i].first - items)
                {
                    
                    ans += 2 * (a[i].first - items);
                    a[e].second -= a[i].first - items;
                    items += a[i].first - items;
                }
                else
                {
                    items += a[e].second;
                    ans += 2 * a[e].second;
                    a[e].second = 0;
                    e--;
                }
                if (e < 0)
                    break;
            }
            i--;
        }
    }
    cout << ans << endl;

    return 0;
}