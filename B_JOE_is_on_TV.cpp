#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n;
    cin >> n;
    long double ans = 0;
    for (lol i = 1; i <= n; i++)
    {
        ans += 1 / (long double)i;
    }
    cout << fixed << setprecision(12) << ans;
}