#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s;
    lol k;
    cin >> s >> k;
    lol f[26];
    memset(f, 0, sizeof(f));
    for (auto c : s)
        f[c - 'a']++;
    lol ans = 0;
    while (k)
    {
        lol mn = -1;
        for (lol i = 0; i < 26; i++)
        {
            if (f[i] != 0)
            {
                if (mn == -1)
                    mn = i;
                else if (f[mn] > f[i])
                    mn = i;
            }
        }
        if (mn == -1)
            break;
        if (f[mn] >= k)
        {
            f[mn] -= k;

            k = 0;
        }
        else
        {
            k -= f[mn];

            f[mn] = 0;
        }
    }
    for (lol i = 0; i < 26; i++)
    {
        if (f[i] != 0)
            ans++;
    }
    cout << ans << endl;
    for (auto c : s)
    {
        if (--f[c-'a'] >= 0)
            cout << c;
    }

    return 0;
}