#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n;
    char k;
    cin >> n >> k;
    lol ans = 0;
    while (n--)
    {
        string s;
        cin >> s;
        bool f[k - '0' + 1];
        memset(f, false, sizeof(f));
        for (lol i = 0; i < s.size(); i++)
        {
            if (s[i] <= k)
            {
                f[s[i] - '0'] = true;
            }
        }
        bool q = true;
        for (lol i = 0; i < k - '0' + 1; i++)
        {
            if (!f[i])
            {
                q = false;
                break;
            }
        }
        if (q)
            ans++;
    }
    cout << ans;

    return 0;
}