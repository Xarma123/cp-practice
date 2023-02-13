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
        lol ans[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        lol v = 0;
        lol c = 0;
        lol mx = 0;
        lol st = -1;
        for (lol i = 0; i < n; i++)
        {
            c++;
            lol j = i + 1;
            while (j < n && a[j] == a[i])
                j++;
            if (j - i >= 2)
                st = i;
            for (lol k = i; k < j; k++)
            {
                ans[k] = v;
                mx = max(mx, v);
            }
            v = 1 - v;
            i = j - 1;
        }
        if (c == 1)
        {
            cout << mx + 1 << '\n';
            for (lol i = 0; i < n; i++)
            {
                cout << ans[i] + 1 << ' ';
            }
            cout << '\n';
        }
        else
        {
            if (a[0] == a[n - 1])
                c--;
            if (c % 2)
            {
                if (st != -1)
                {
                    v = 1 - ans[st];
                    for (lol i = st + 1; i < n; i++)
                    {
                        lol j = i + 1;
                        while (j < n && a[j] == a[i])
                            j++;
                        for (lol k = i; k < j; k++)
                        {
                            ans[k] = v;
                        }
                        v = 1 - v;
                        i = j - 1;
                    }
                }
                else if (a[0] != a[n - 1])
                {
                    mx = 2;
                    ans[n - 1] = 2;
                }
            }
            cout << mx + 1 << '\n';
            for (lol i = 0; i < n; i++)
            {
                cout << ans[i] + 1 << ' ';
            }
            cout << '\n';
        }
    }

    return 0;
}