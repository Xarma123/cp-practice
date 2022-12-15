#include <bits/stdc++.h>
#define lol long long
using namespace std;
map<lol, multiset<lol>> mp;
lol solve(lol x, lol y)
{

    if (__gcd(x, y) != 1)
    {
        return 0;
    }
    else if (abs(x - y) == 1)
        return -1;
    else if (x % 2 == y % 2)
        return 1;
    else
    {
        return 1 + solve(x + 1, y + 1);
    }
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    lol n;
    cin >> n;
    while (n--)
    {
        lol x, y;
        cin >> x >> y;
        if (x < y)
            swap(x, y);
        if (mp.count(y - x))
        {
            
            
        }
        cout << solve(x, y) << endl;
    }

    return 0;
}