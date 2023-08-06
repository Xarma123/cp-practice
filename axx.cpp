#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve()
{
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n), b(n);
    for (ll i = n - 1; i >= 0; i--)
    {
        cin >> a[n - 1 - i];
        b[n - 1 - i] = a[n - 1 - i];
    }

    ll st = 0;
    ll end = 1e18;
    while (st + 1 != end)
    {
        ll middle = (s + e) / 2ll, mncost = LONG_LONG_MAX;
        ll i = 0;
        while (i < n)
        {
            ll cost = 0;
            ll j = i;
            while (j < n)
            {
                if (a[j] >= middle - (j - i))
                    break;
                else if (j == n - 1)
                {
                    cost = LONG_LONG_MAX;
                    break;
                }
                else
                {
                    cost += (m - (j - i)) - a[j];
                }
                j++;
            }
            mncost = min(mnc, cost);
            i++;
        }
        if (mncost <= k)
            st = middle;
        else
            end = middle;
    }
    cout << st << '\n';
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}