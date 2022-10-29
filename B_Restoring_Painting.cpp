#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, a, b, c, d;
    cin >> n >> a >> b >> c >> d;
    lol sum = LONG_LONG_MAX;
    sum = min(a + c + 2 * 1ll * n, sum);
    sum = min(a + b + 2 * 1ll * n, sum);
    sum = min(d + b + 2 * 1ll * n, sum);
    sum = min(d + c + 2 * 1ll * n, sum);
    lol ans = 0;
    for (lol i = max(a + b + 2, max(a + c + 2, max(b + d + 2, d + c + 2))); i <= sum; i++)
    {
        
        ans +=max(0ll, min(n,min(i - 1 - a - b, min(i - 1 - a - c, min(i - 1 - b - d, i - 1 - c - d)))) -
               max(1ll,max(i - n - a - b, max(i - n - a - c, max(i - n - b - d, i - n - c - d))))+ 1);
       
    }
    cout << ans;

    return 0;
}