#include <bits/stdc++.h>
#define lol long long
using namespace std;
lol powmod(lol x, lol n)
{

    lol res = 1;
    for (lol i = 1; i <= n; i++)
        res = (res * x) % 1000000007;
    return res;
}
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol n, k;
        cin >> n >> k;
        cout << powmod(n, k) << endl;
    }

    return 0;
}