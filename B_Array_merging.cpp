#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol n;
        cin >> n;
        lol a[n], b[n], fa[2ll * n + 1], fb[2ll * n + 1];
        memset(fa, 0, sizeof(fa));
        memset(fb, 0, sizeof(fb));
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (lol i = 0; i < n; i++)
        {
            lol j = i + 1;
            while (j < n && a[j] == a[j - 1])
                j++;
            fa[a[i]] = max(fa[a[i]], j - i);
            i = j - 1;
        }

        for (lol i = 0; i < n; i++)
        {
            cin >> b[i];
        }
        for (lol i = 0; i < n; i++)
        {
            lol j = i + 1;
            while (j < n && b[j] == b[j - 1])
                j++;
            fb[b[i]] = max(fb[b[i]], j - i);
            i = j - 1;
        }
        lol ans = 0;
        for (lol i = 0; i < 2ll * n + 1; i++)
        {
            ans = max(ans, fa[i] + fb[i]);
        }
        cout << ans << '\n';
    }
}