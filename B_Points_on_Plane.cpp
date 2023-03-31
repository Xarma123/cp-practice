#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol t;
    cin >> t;
    while (t--)
    {
        lol a;
        cin >> a;
        // 4*n(n+1)/2+1 >=a
        lol s = -1, e = 1e10;
        while (s != e - 1)
        {
            lol mid = (s + e) / 2;
            if (mid == -1)
                s = mid;
            else if (powl(mid + 1, 2) >= a)
                e = mid;
            else
                s = mid;
        }
        cout << e << '\n';
    }

    return 0;
}