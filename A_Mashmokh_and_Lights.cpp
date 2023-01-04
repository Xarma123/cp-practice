#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, m;
    cin >> n >> m;
    lol l = n + 1;
    lol ans[n];
    memset(ans, -1, sizeof(ans));
    while (m--)
    {
        lol c;
        cin >> c;
        if (c < l)
        {
            ans[c - 1] = c;
            l = c;
        }
    }
    for (lol i = 0; i < n; i++)
    {
        if (ans[i] == -1)
        {
            ans[i] = ans[i - 1];
            lol j = i + 1;
            while (j < n && ans[j] == -1)
            {
                ans[j] = ans[j - 1];
                j++;
            }
        }
    }
    for (lol i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}