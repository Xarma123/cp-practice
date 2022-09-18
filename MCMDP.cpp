#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long int
const ll N = 100;

ll n = 4;
vector<vector<ll>> dp(1000, vector<ll>(1000, 0));

int McM(ll arr[], ll n)
{

	for (ll len = 2; len < n; len++)
	{
		for (ll start = 1; start <= n - len; start++)
		{
			ll end1 = start + len - 1;
			dp[start][end1] = 1e10;

			for (ll i = start; i <= end1 - 1; i++)
			{
				ll val = dp[start][i] + dp[i + 1][end1] + arr[start - 1] * arr[i] * arr[end1];
				dp[start][end1] = min(dp[start][end1], val);
			}
		}
	}

	return dp[1][n - 1];
}

int main()
{
	ll arr[4] = {1, 2, 3, 4};

	ll ans = McM(arr, n);
	cout << ans << endl;

	return 0;
}
