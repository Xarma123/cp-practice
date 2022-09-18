#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    string t;
    cin >> t;

    pair<lol, lol> q[m];
    lol j = 0;
    for (lol i = 0; i < m; i++)
    {
        while (s[j] != t[i])
        {
            j++;
            if (j == n)
                break;
        }

        q[i] = make_pair(j, 0);
        j++;
    }
    j = n - 1;
    for (lol i = m - 1; i >= 0; i--)
    {
        while (s[j] != t[i])
        {
            j--;
            if (j < 0)
                break;
        }

        q[i] = make_pair(q[i].first, j);
        j--;
    }
    lol ans = 0;
    for (lol i = 1; i < m; i++)
    {
        ans = max(ans, q[i].second - q[i - 1].first);
    }
    cout << ans << endl;

    return 0;
}