#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, t, k, d;
    cin >> n >> t >> k >> d;
    lol q = ceill(n / (long double)k);
    lol st = 0;
    lol e = 1e18;
    while (st != e - 1)
    {
        lol time = (st + e) / 2;
        lol c = (time / t) * k;
        if (time >= d)
        {
            c += ((time - d) / t) * k;
        }
        if (c >= n)
            e = time;
        else
            st = time;
    }
    if (e < q * t)
    {
        cout << "YES";
    }
    else
        cout << "NO";

    return 0;
}