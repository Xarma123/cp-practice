#include <bits/stdc++.h>
#define lol long double
using namespace std;

lol d(vector<pair<lol, lol>> &a, lol n)
{
    if (n == 0 || n == 1)
    {
        return LONG_LONG_MAX;
    }
    if (n == 2)
    {
        return sqrt(pow((a[0].first - a[1].first), 2) + pow((a[0].second - a[1].second), 2));
    }  
    lol left = 
    
}
int main()
{
    lol n;
    cin >> n;
    vector<pair<lol, lol>> s;
    for (lol i = 0; i < n; i++)
    {
        lol a, b;
        cin >> a >> b;
        s.push_back(make_pair(a, b));
    }  
    d(s, n);

    return 0;
}