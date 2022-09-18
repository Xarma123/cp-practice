#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol x;
    cin >> x;
    lol ans = 0;
    while (x > 0)
    {
        x = (x & (x - 1));
        ans++;
    }
    cout << ans;

    return 0;
}