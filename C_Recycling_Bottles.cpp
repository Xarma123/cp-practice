#include <bits/stdc++.h>
#define lol long double
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol ax, ay, bx, by, tx, ty;
    cin >> ax >> ay >> bx >> by >> tx >> ty;
    lol n;
    cin >> n;
    vector<vector<lol>> v;
    lol cv = 0;
    multiset<pair<lol, pair<lol, lol>>> x1;
    while (n--)
    {
        lol x, y;
        cin >> x >> y;
        v.push_back({x, y});
        cv += (long double)2 * sqrtl(powl(tx - x, 2) + powl(ty - y, 2));
        x1.insert({(long double)(-sqrtl(powl(bx - x, 2) + powl(by - y, 2))), {sqrtl(powl(tx - x, 2) + powl(ty - y, 2)), 2}});
        x1.insert({(long double)(-sqrtl(powl(ax - x, 2) + powl(ay - y, 2))), {sqrtl(powl(tx - x, 2) + powl(ty - y, 2)), 1}});
    }
    lol ans = cv;
    lol q = (*x1.begin()).first; 
    

    return 0;
}