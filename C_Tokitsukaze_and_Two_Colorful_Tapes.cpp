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
        lol n;
        cin >> n;
        lol to[n + 1];
        lol ca[n];
        for (lol i = 0; i < n; i++)
            cin >> ca[i];
        for (lol i = 0; i < n; i++)
            cin >> to[ca[i]];
        bool vis[n + 1];
        memset(vis, false, sizeof(vis));
        lol x = 0;
        for (lol i = 0; i < n; i++)
        {
            if (!vis[ca[i]])
            {

                lol c = 0;
                lol j = ca[i];
                while (!vis[j])
                {
                    vis[j] = true;
                    c++;
                    j = to[j];
                }
                x += c / 2;
            }
        }
        cout << 2ll * (n - x) * 1ll * x << '\n';
    }

    return 0;
}