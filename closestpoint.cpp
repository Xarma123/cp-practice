#include <bits/stdc++.h>
#define lol long long
using namespace std;
long double dis(vector<pair<lol, lol>> &p, lol n)
{
    if (n == 0 || n == 1)
    {
        return FLT_MAX;
    }
    if (n == 2)
    {
        return sqrt(pow((p[0].first - p[1].first), 2) + pow((p[0].second - p[1].second), 2));
    }
    if (n == 3)
    {
        return min(sqrt(pow((p[0].first - p[1].first), 2) + pow((p[0].second - p[1].second), 2)), min(sqrt(pow((p[0].first - p[2].first), 2) + pow((p[0].second - p[2].second), 2)), sqrt(pow((p[1].first - p[2].first), 2) + pow((p[1].second - p[2].second), 2))));
    }
    long double lf = dis(p, n / 2);
    vector<pair<lol, lol>> p2;
    for (lol i = n / 2; i < n; i++)
    {
        p2.push_back(make_pair(p[i].first, p[i].second));
    }

    long double rf = dis(p2, n - n / 2);
    long double d = min(lf, rf);
    lol a = p[n / 2].first + d;
    lol b = LONG_LONG_MAX;
    auto it = upper_bound(p.begin(), p.end(), make_pair(a, b));
    a = p[n / 2].first - d;
    b = LONG_LONG_MAX;
    auto it2 = lower_bound(p.begin(), p.end(), make_pair(a, b));
    vector<pair<lol, lol>> s;
    for (auto i = it2; i != it; i++)
    {
        s.push_back(make_pair( (*i).second,(*i).first));
    }
   sort(s.begin(),s.end());
   for (lol i = 0; i < s.size(); ++i)
        for (lol j = i+1; j < s.size() && (s[j].first - s[i].first) < d; ++j)
           {  if( sqrt(pow((s[i].first - s[j].first), 2) + pow((s[i].second - s[j].second), 2)) < d  ) 
              d = sqrt(pow((s[i].first - s[j].first), 2) + pow((s[i].second - s[j].second), 2));
           } 
           return d;

}
int main()
{
    lol n;
    cin >> n;
    vector<pair<lol, lol>> polol;
    for (lol i = 0; i < n; i++)
    {
        lol x, y;
        cin >> x >> y;
        polol.push_back(make_pair(x, y));
    }
    sort(polol.begin(), polol.end());
    cout<<setprecision(9) << dis(polol, n);

    return 0;
}