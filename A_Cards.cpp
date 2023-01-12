#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n;
    cin >> n;
    lol a[n];
    lol s = 0;
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
        s += a[i];
    }
    lol v = s / (n / 2);
    bool vis[n];
    memset(vis, false, sizeof(vis));
    for (lol i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            lol j;
            for (j = i + 1; j < n; j++)
            {
                if (a[i] + a[j] == v && !vis[j])
                    break;
            }
            cout << i + 1 << " " << j + 1 << endl;
            vis[j] = true;
        }
    }

    return 0;
}