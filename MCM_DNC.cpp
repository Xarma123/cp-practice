#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long int
const ll N = 1e6;

ll arr[4] = {1, 2, 3, 4};

ll McM(ll start, ll end)
{
    if (start == end)
    {
        return 0;
    }

    ll mn = 1e10, val = 0;

    for (ll i = start; i < end; i++)
    {
        val = McM(start, i) + McM(i + 1, end) + arr[start - 1] * arr[i] * arr[end];
        mn = min(mn, val);
    }

    return mn;
}

int main()
{

    ll n = 4;
    ll ans = McM(1, n - 1);
    cout << ans << endl;

    return 0;
}
