#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol t;
    cin >> t;
    while (t--)
    {
        lol n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        lol c[n];
        memset(c, 0, sizeof(c));
        for (lol i = 0; i < n; i++)
        {
            if (s[i] == '1')
            {
                lol l = max(0ll, i - k);
                lol r = min(n - 1, i + k);
                c[l]++;
                if (r + 1 < n)
                    c[r + 1]--;
            }
        }
        for (lol i = 1; i < n; i++)
        {
            c[i] += c[i - 1];
        }
        lol ans = 0;
        for (lol i = 0; i < n; i++)
        {
            if (c[i] == 0)
            {
                lol j = i + 1;
                while (j < n && c[j] == c[i])
                    j++;

                ans += (j - 1 - i) / (k + 1) + 1;
                i = j - 1;
            }
        }
        cout << ans << '\n';
    }
}