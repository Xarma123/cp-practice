#include <bits/stdc++.h>
#define lol long long
using namespace std;
lol n, x, y;
bool check(lol t)
{
    lol c = 0;
    if (c >= n)
        return true;
    if (t < min(x, y))
    {
        return false;
    }
    t -= min(x, y);
    c++;
    if (c >= n)
        return true;

    c += t / x + t / y;
    if (c >= n)
        return true;
    return false;
}
int main()
{
    cin >> n >> x >> y;

    lol s = 0;
    lol e = max(x, y) * n;
    while (s != e - 1)
    {
        lol m = (s + e) / 2;
        if (check(m))
            e = m;
        else
            s = m;
    }
    cout << e;

    return 0;
}