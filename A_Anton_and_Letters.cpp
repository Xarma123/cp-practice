#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    char c;
    lol f[26];
    for (lol i = 0; i < 26; i++)
    {
        f[i] = 0;
    }

    while (1)
    {
        cin >> c;
        if ('a' <= c && c <= 'z')
            f[c - 'a']++;
        if (c == '}')
            break;
    }
    lol ans = 0;
    for (lol i = 0; i < 26; i++)
    {
        if (f[i] != 0)
            ans++;
    }
    cout << ans;

    return 0;
}