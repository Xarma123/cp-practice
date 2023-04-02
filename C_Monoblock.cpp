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
    lol a[n];
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    lol c = 0;
    lol ans = 1;
    c = 1;
    for (lol i = 1; i < n; i++)
    {

        if (a[i - 1] == a[i])
        {
            c = c + 1;
            ans += c;
        }
        else
        {
            c = c + 1 + i;
            ans += c;
        }
    }

    while (m--)
    {
        lol i, x;
        cin >> i >> x;
        i--;
        lol d1 = 0;
        if (i - 1 >= 0)
        {
            if (a[i] != a[i - 1])
            {
                if (x == a[i - 1])
                {
                    d1 = -i;
                }
            }
            else
            {
                if (x != a[i - 1])
                {
                    d1 = i;
                }
            }
        }
        lol d2 = 0;
        if (i + 1 < n)
        {

            if (a[i + 1] != a[i])
            {
                if (x == a[i + 1])
                {
                    d2 = -i - 1;
                }
            }
            else
            {
                if (x != a[i + 1])
                {
                    d2 = i + 1;
                }
            }
        }
        a[i] = x;
        ans += d1 * 1ll * (n - i) + (n - i - 1) * 1ll * d2;
        cout << ans << '\n';
    }

    return 0;
}