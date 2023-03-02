#include <bits/stdc++.h>
#define lol long long
using namespace std;
lol cal(lol a)
{
    return (sqrt(a) - (long long)cbrt(a));
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
   
    lol t;
    cin >> t;
    while (t--)
    {
        lol x;
        cin >> x;
        lol st = 1, e = LONG_LONG_MAX;
        while (st != e - 1)
        {
            lol m = (st + e) / 2;
            if (cal(m) >= x)
                e = m;
            else
                st = m;
        }
        cout << e << '\n';
    }

    return 0;
}