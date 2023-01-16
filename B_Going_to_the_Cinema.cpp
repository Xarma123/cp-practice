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
        lol a[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        sort(a, a + n);
        lol tot = 0;
        lol ans = 0;
        for (lol i = 0; i < n; i++)
        {
            lol j = i + 1;
            while (j < n && a[j] == a[i])
                j++;
            tot += j - i;
            if (a[i] + 1 <= tot)
            {
                if (!(j < n && a[j] <= tot))
                    ans++;
            }
            i = j - 1;
        }
        if (a[0])
            ans++;
        cout << ans << '\n';
    }

    return 0;
}