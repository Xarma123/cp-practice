#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol a, b, c, d;
    cin >> a >> b >> c >> d;
    vector<lol> x(3);
    x[0] = a;
    x[1] = b;
    x[2] = c;
    sort(x.begin(), x.end());
    lol ans = 0;
    if (x[1] - x[0] < d)
    {
        ans += d - (x[1] - x[0]);
        
    }
    if (x[2] - x[1] < d)
    {
        ans += d - (x[2] - x[1]);
        
    }
    cout << ans;
}