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
        lol n;
        cin >> n;
        lol a[n];
        map<lol, lol> f;
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
            for (lol j = 2; j * 1ll * j <= a[i]; j++)
            {
                while (a[i] % j == 0)
                {
                    a[i] /= j;
                    f[j]++;
                }
            }
            if (a[i] > 1)
                f[a[i]]++;
        }
        bool ans = true;
        for (auto e : f)
        {
            if (e.second % n != 0)
            {
                ans = false;
            }
        }
        if (ans)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}