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
    lol c = 0;
    lol ans = 0;
    for (lol i = 0; i < n; i++)
    {
        lol q = 0;
        cin >> q;
        ans += abs(q - c);
        c = q;
    }
    cout << ans;

    return 0;
}