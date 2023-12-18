#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n;
    cin >> n;
    lol a[n];
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    lol pmax[n];
    for (lol i = 0; i < n; i++)
    {
        pmax[i] = i;
        if (i)
        {
            if (a[i] < a[pmax[i - 1]])
                pmax[i] = pmax[i - 1];
        }
    }
    lol sufmax[n];
    for (lol i = n - 1; i >= 0; i--)
    {
        sufmax[i] = i;
        if (i < n - 1)
        {
            if (a[i] < a[sufmax[i + 1]])
                sufmax[i] = sufmax[i + 1];
        }
    }
    lol sufans[n];
    for (lol i = n - 1; i >= 0; i--)
    {
        sufans[i] = a[i] + i;
        if (i < n - 1)
        {
            sufans[i] = max(sufans[i + 1], sufans[i]);
        }
    }
    lol pans[n];
    for (lol i = 0; i < n; i++)
    {
        pans[i] = a[i] + n - 1 - i;
        if (i)
        {
            pans[i] = max(pans[i], pans[i - 1]);
        }
    }
    lol ans = LONG_LONG_MAX;
    for (lol i = 0; i < n; i++)
    {
        lol c = a[i];
        lol l = -1;
        if (i)
            l = pmax[i - 1];
        lol r = -1;
        if (i < n - 1)
            r = sufmax[i + 1];
        if (l == -1 && r == -1)
        {
            ans = min(ans, c);
            continue;
        }
        else if (l == -1)
        {
            c = max(c, sufans[r]);
        }
        else if (r == -1)
        {
            c = max(c, pans[l]);
        }
        else
        {
            c = max(c, sufans[r]);
            c = max(c, pans[l]);
        }
        ans = min(ans, c);
    }
    cout << ans;

    return 0;
}
