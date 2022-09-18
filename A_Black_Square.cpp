#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol a[4];
    for (lol i = 0; i < 4; i++)
    {
        cin >> a[i];
    }
    string s;
    cin >> s;
    lol ans = 0;
    for (lol i = 0; i < s.size(); i++)
    {
        ans += a[s[i] - '1'];
    }
    cout << ans;

    return 0;
}