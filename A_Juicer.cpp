#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, b, d;
    cin >> n >> b >> d;
    lol t = 0;
    lol ans = 0;
    for (lol i = 0; i < n; i++)
    {
        lol q;
        cin >> q;
        if (q > b)
            continue;
        t += q;
        if (t > d)
        {
            ans++;
            t = 0;
        }
    }
    cout << ans;

    return 0;
}