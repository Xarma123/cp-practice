#include <bits/stdc++.h>
#define lol long long
using namespace std;
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
        lol w = 0;
        for (lol i = 0; i < k; i++)
        {
            if (s[i] == 'W')
                w++;
        }
        lol ans = w;
        for (lol i = k; i < n; i++)
        {
            if (s[i - k] == 'W')
                w--;
            if (s[i] == 'W')
                w++;
            ans = min(ans, w);
        }
        cout << ans << endl;
    }

    return 0;
}