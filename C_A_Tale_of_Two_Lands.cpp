#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol n;
    cin >> n;
    vector<lol>  p;
    for (lol i = 0; i < n; i++)
    {
        lol t;
        cin >> t;
        if (t < 0)
            p.push_back(-t);
        else
            p.push_back(t);
    }
   
    sort(p.begin(), p.end());
    lol ans = 0;
    for (auto i = p.begin(); i != p.end(); i++)
    {
        lol v = 2 * 1ll * (*i);

        lol j = upper_bound(i, p.end(), v) - i - 1;
        ans += j;
    }
  
    cout << ans;

    return 0;
}