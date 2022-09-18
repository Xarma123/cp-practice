#include <bits/stdc++.h>
#define lol long long
using namespace std;
lol n, k;
vector<pair<lol, lol>> a;
bool check(lol c)
{
    lol ans = 0;
    for (lol i = 0; i < n; i++)
    {
        if (a[i].first < c)
        {
            if(c<=a[i].second)
            {
                ans+=c-a[i].first;
            }
            else
            {
                ans+= a[i].second-a[i].first+1;
            }
        }
    }
    return ans <= k;
}
int main()
{
    cin >> n >> k;
    lol s = INT_MAX, e = INT_MIN;
    for (lol i = 0; i < n; i++)
    {
        lol t, t1;
        cin >> t >> t1;
        s = min(s, t);

        e = max(e, t1);
        a.push_back(make_pair(t, t1));
    }
    e = e+1;
    while (s != e - 1)
    {
        lol m = (s + e) / 2;
        if (check(m))
            s = m;
        else
            e = m;
    }
    cout << s;
    return 0;
}