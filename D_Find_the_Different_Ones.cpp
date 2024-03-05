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
        lol n;
        cin >> n;
        lol a[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        lol nx[n];
        for (lol i = 0; i < n; i++)
        {
            lol j = i + 1;
            while (j < n && a[j] == a[i])
            {
                j++;
            }
            for (lol k = i; k < j; k++)
            {
                nx[k] = j;
            }
            i = j - 1;
        }
        lol q;
        cin >> q;
        while (q--)
        {
            lol l, r;
            cin >> l >> r;
            l--;
            r--;
            if (nx[l] > r)
            {
                cout << -1 << " " << -1 << '\n';
            }
            else
                cout << l + 1 << " " << nx[l] + 1 << '\n';
        }
    }

    return 0;
}
