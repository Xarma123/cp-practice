#include <bits/stdc++.h>
#define lol long long
using namespace std;

int main()
{
    lol n;
    cin >> n;
    lol d, e;
    cin >> d >> e;
    e = e * 5;
    lol ans = LONG_LONG_MAX;
    for (lol i = 0; i * d <= n; i++)
    {
        lol c = n - i * d;
        c = c - (c / e) * e;
        ans = min(ans, c);
    }
    cout<<ans;

    return 0;
}