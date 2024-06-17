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
        lol b[n - 1];
        for (lol i = 1; i < n; i++)
        {
            b[i - 1] = __gcd(a[i], a[i - 1]);
        }
        bool inpre[n - 1];
        memset(inpre, true, sizeof(inpre));
        for (lol i = 1; i < n - 1; i++)
        {
            if (b[i] >= b[i - 1] && inpre[i - 1])
            {
                inpre[i] = true;
            }
            else
            {
                inpre[i] = false;
            }
        }
        lol insuf[n - 1];
        memset(insuf, true, sizeof(insuf));
        for (lol i = n - 3; i >= 0; i--)
        {
            if (b[i] <= b[i + 1] && insuf[i + 1])
            {
                insuf[i] = true;
            }
            else
                insuf[i] = false;
        }
        bool ans = inpre[n - 2];
        for (lol i = 0; i < n; i++)
        {
            if (i == 0)
            {
                if (insuf[i + 1])
                {
                    ans = true;
                }
            }
            else if (i == n - 1)
            {
                if (inpre[n - 3])
                    ans = true;
            }
            else
            {
                // i-1 i
                // __gcd(a[i-1],a[i+1])
                if (i - 2 >= 0)
                {
                    if (!inpre[i - 2])
                        continue;
                }
                if (i + 1 < n - 1)
                {
                    if (!insuf[i + 1])
                        continue;
                }
                lol v = __gcd(a[i - 1], a[i + 1]);
                if (i - 2 >= 0 && i + 1 < n - 1)
                {
                    if (b[i - 2] <= v && b[i + 1] >= v)
                    {
                        ans = true;
                    }
                }
                else if (i - 2 >= 0)
                {
                    if (b[i - 2] <= v)
                        ans = true;
                }
                else if (i + 1 < n - 1)
                {
                    if (b[i + 1] >= v)
                        ans = true;
                }
                else
                    ans = true;
            }
        }
        if (ans)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}
