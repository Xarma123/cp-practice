#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol t;
    cin >> t;
    while (t--)
    {
        lol n, k, pb, ps;
        cin >> n >> k >> pb >> ps;
        lol p[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> p[i];
        }
        lol a[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        lol ansb = LONG_LONG_MIN;
        lol i = pb - 1;
        bool vis[n];
        memset(vis, false, sizeof(vis));
        lol psum = 0;
        lol count = 0;
        while (!vis[i] && count < k)
        {
            psum += a[i];
            vis[i] = true;
            count++;
            ansb = max(ansb, ((k - count) * 1ll * (a[i]) + psum));
            i = p[i]-1;
        }
        lol anss = LONG_LONG_MIN;
        i = ps - 1;
        memset(vis, false, sizeof(vis));
        psum = 0;
        count = 0;
        while (!vis[i] && count < k)
        {
            psum += a[i];
            vis[i] = true;
            count++;
            anss = max(anss, ((k - count) * 1ll * (a[i]) + psum));
            i = p[i]-1;
        }
        if (ansb > anss)
        {
            cout << "Bodya\n";
        }
        else if (ansb == anss)
        {
            cout << "Draw\n";
        }
        else
            cout << "Sasha\n";
    }

    return 0;
}
