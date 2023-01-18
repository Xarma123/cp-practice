#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n;
    cin >> n;
    lol d[n];
    lol s = 0;
    for (lol i = 0; i < n; i++)
    {
        cin >> d[i];
        s += d[i];
    }
    lol a, b;
    cin >> a >> b;
    a--;
    b--;
    if (a > b)
        swap(a, b);
    lol ans = 0;
    for (lol i = a; i < b; i++)
    {
        ans += d[i];
    }
    ans = min(ans, s - ans);
    cout << ans;

    return 0;
}