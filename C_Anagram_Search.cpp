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
    lol f[26];
    memset(f, 0, sizeof(f));
    for (auto c : b)
        f[c - 'a']--;
    if (b.size() > a.size())
        cout << 0;
    else
    {
        for (lol i = 0; i < b.size(); i++)
        {
            if (a[i] != '?')
                f[a[i] - 'a']++;
        }
        lol ans = 0;
        for (lol i = 0; i + b.size() - 1 < a.size(); i++)
        {
            if (i)
            {
                if (a[i - 1] != '?')
                    f[a[i - 1] - 'a']--;
                if (a[i + b.size() - 1] != '?')
                    f[a[i + b.size() - 1] - 'a']++;
            }
            lol j;
            for (j = 0; j < 26; j++)
            {
                if (f[j] > 0)
                    break;
            }
            if (j == 26)
                ans++;
        }
        cout << ans;
    }

    return 0;
}