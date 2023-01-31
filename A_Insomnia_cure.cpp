#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol k, l, m, n, d;
    cin >> k >> l >> m >> n >> d;
    lol ans = 0;
    for (lol i = 1; i <= d; i++)
    {
        if (i % k == 0 || i % l == 0 || i % m == 0 || i % n == 0)
            ans++;
    }
    cout << ans;

    return 0;
}