#include <bits/stdc++.h>
using namespace std;
int main()
{
   long  double n, w;
    cin >> n >> w;
    multimap<long double, pair<long double, long double>, greater<long double>> a;
    while (n--)
    {
        long double v, b;
        cin >> v >> b;
        a.insert(make_pair(v/b, make_pair(v, b))) ;
    }
   long  double ans = 0;
    for (auto i = a.begin(); i != a.end() && w != 0; i++)
    {
        if (w >= (*i).second.second)
        {
            w -= (*i).second.second;
            ans += (*i).second.first;
        }
        else
        {

            ans += w * ((*i).first);
            w = 0; 
        } 
    }
    cout<<ans; 

    return 0;
}