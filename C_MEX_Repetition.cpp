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
        lol n, k;
        cin >> n >> k;
        lol a[n + 1];
        bool mn[n + 1];
        memset(mn, false, sizeof(mn));
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
            mn[a[i]] = true;
        }
        lol mex;
        for (lol i = 0; i <= n; i++)
        {
            if (!mn[i])
            {
                mex = i;
                break;
            }
        }
        a[n] = mex;
        k %= n + 1;
        for (lol i = 0; i < n; i++)
        {
            lol j = i - k;
            if (j < 0)
            {
                j += n + 1;
            }
            cout << a[j] << " ";
        }
        cout << '\n';
    }
}