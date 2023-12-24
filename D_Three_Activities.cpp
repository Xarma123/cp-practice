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
        lol a[n], b[n], c[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (lol i = 0; i < n; i++)
        {
            cin >> b[i];
        }
        for (lol i = 0; i < n; i++)
        {
            cin >> c[i];
        }
        lol p[n];
        p[0] = 0;
        lol mxa[n];
        lol mxb[n];
        for (lol i = 0; i < n; i++)
        {
            if (i == 0)
            {
                mxa[i] = a[i];
                mxb[i] = b[i];
            }
            else
            {
                p[i] = max(max(a[i] + mxb[i - 1], b[i] + mxa[i - 1]), p[i - 1]);
                mxa[i] = max(mxa[i - 1], a[i]);
                mxb[i] = max(mxb[i - 1], b[i]);
            }
        }

        lol suf[n];
        suf[n - 1] = 0;
        lol mxa1[n];
        lol mxb1[n];
        for (lol i = n - 1; i >= 0; i--)
        {
            if (i == n - 1)
            {
                mxa1[i] = a[i];
                mxb1[i] = b[i];
            }
            else
            {
                suf[i] = max(max(a[i] + mxb1[i + 1], b[i] + mxa1[i + 1]), suf[i + 1]);
                mxa1[i] = max(mxa1[i + 1], a[i]);
                mxb1[i] = max(mxb1[i + 1], b[i]);
            }
        }
        lol ans = 0;
        for (lol i = 1; i < n - 1; i++)
        {
            ans = max(ans, c[i] + p[i - 1]);
            ans = max(ans, c[i] + suf[i + 1]);
            ans = max(ans, c[i] + mxa[i - 1] + mxb1[i + 1]);
            ans = max(ans, c[i] + mxb[i - 1] + mxa1[i + 1]);
        }
        ans = max(ans, c[0] + suf[1]);
        ans = max(ans, c[n - 1] + p[n - 2]);
        cout << ans << '\n';
    }

    return 0;
}
