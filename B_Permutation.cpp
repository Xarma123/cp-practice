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
    set<lol> x;

    for (lol i = 1; i <= n; i++)
    {
        lol t;
        cin >> t;
        x.insert(t);
    }
    lol ans = 0;
    for (lol i = 1; i <= n; i++)
    {
        if (x.count(i))
            ans++;
    }
    ans = n - ans;
    cout << ans;

    return 0;
}