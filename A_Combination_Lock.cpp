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
    string a, b;
    cin >> a >> b;
    lol ans = 0;
    for (lol i = 0; i < n; i++)
    {
        ans += min(10 - abs(a[i] - b[i]), abs(a[i] - b[i]));
    }
    cout << ans;

    return 0;
}