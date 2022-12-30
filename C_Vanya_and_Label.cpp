#include <bits/stdc++.h>
#define lol long long
using namespace std;
lol m = 1e9 + 7;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s;
    cin >> s;
    lol f[64];
    memset(f, 0, sizeof(f));
    for (lol i = 0; i < 64; i++)
    {
        for (lol j = 0; j < 64; j++)
        {
            f[(i & j)]++;
        }
    }
    lol ans = 1;
    for (auto c : s)
    {
        if ('0' <= c && c <= '9')
        {
            ans = (ans*1ll*f[(c - '0')])%m;
        }
        if ('A' <= c && c <= 'Z')
        {
            ans = (ans*1ll*f[(c - 'A') + 10])%m;
        }
        if ('a' <= c && c <= 'z')
        {
            ans = (ans*1ll*f[(c - 'a') + 36])%m;
        }
        if (c == '-')
            ans = (ans*1ll*f[62])%m;
        if (c == '_')
            ans = (ans*1ll*f[63])%m;
    }
    cout << ans;

    return 0;
}