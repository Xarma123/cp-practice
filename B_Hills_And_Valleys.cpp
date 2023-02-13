#include <bits/stdc++.h>
#define lol long long
using namespace std;
lol a[300005];
lol n;
bool check(lol i)
{
    if (i > 0 && i < n - 1)
    {
        if (a[i] > a[i - 1] && a[i] > a[i + 1])
            return true;
        if (a[i] < a[i - 1] && a[i] < a[i + 1])
            return true;
    }
    return false;
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        lol ans = 0;
        bool old[n];
        old[0] = old[n - 1] = false;
        for (lol i = 1; i < n - 1; i++)
        {
            old[i] = false;
            if (a[i] > a[i - 1] && a[i] > a[i + 1])
            {
                ans++;
                old[i] = true;
            }
            if (a[i] < a[i - 1] && a[i] < a[i + 1])
            {
                ans++;
                old[i] = true;
            }
        }
        lol x = ans;
        for (lol i = 1; i < n - 1; i++)
        {
            lol q = a[i];
            a[i] = a[i - 1];
            ans = min(ans, x - (+old[i] + old[i - 1] + old[i + 1] - check(i) - check(i - 1) - check(i + 1)));
            a[i] = a[i + 1];
            ans = min(ans, x - (+old[i] + old[i - 1] + old[i + 1] - check(i) - check(i - 1) - check(i + 1)));
            a[i] = q;
        }

        cout << ans << '\n';
    }

    return 0;
}