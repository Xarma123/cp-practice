#include <bits/stdc++.h>
#define lol long long
using namespace std;
lol powmod(lol n)
{
    lol res = 1;
    for (lol i = 1; i < n; i++)
        res = (res * 2) % 1000000007;
    return res;
}
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol n, m;
        cin >> n >> m;
        lol l, r, x;
        lol q = 0;
        while (m--)
        {
            cin >> l >> r >> x;
            q = (q | x);
        }
        cout << (q * 1ll * powmod(n)) % (1000000007) << endl;
    }

    return 0;
}