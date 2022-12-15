#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol ans = 0;
    lol n;
    cin >> n;
    while (n--)
    {
        lol x, y;
        cin >> x >> y;
        if (y - x >= 2)
            ans++;
    }
    cout << ans;

    return 0;
}