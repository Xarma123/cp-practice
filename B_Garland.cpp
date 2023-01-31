#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string a, b;
    cin >> a >> b;
    lol fa[26], fb[26];
    memset(fa, 0, sizeof(fa));
    memset(fb, 0, sizeof(fb));
    for (auto c : a)
        fa[c - 'a']++;
    for (auto c : b)
        fb[c - 'a']++;
    lol ans = 0;
    for (lol i = 0; i < 26 && ans != -1; i++)
    {
        if (fa[i] >= fb[i])
        {
            ans += fb[i];
        }
        else if (fb[i])
        {
            if (fa[i])
                ans += fa[i];
            else
                ans = -1;
        }
    }
    cout << ans;

    return 0;
}