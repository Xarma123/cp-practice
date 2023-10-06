#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n;
    cin >> n;
    lol a[n];
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    lol op[n];
    memset(op, -1, sizeof(op));
    lol q;
    cin >> q;
    vector<lol> s[q];
    for (lol i = 0; i < q; i++)
    {
        lol t;
        cin >> t;
        if (t == 1)
        {
            lol p, x;
            cin >> p >> x;
            p--;
            op[p] = i;
            a[p] = x;
            s[i] = {t, p, x};
        }
        else
        {
            lol x;
            cin >> x;
            s[i] = {t, x};
        }
    }
    lol mx = 0;
    lol suf[q + 1];
    suf[q] = mx;
    for (lol i = q - 1; i >= 0; i--)
    {
        suf[i] = mx;
        if (s[i][0] == 2)
        {
            suf[i] = max(suf[i], s[i][1]);
            mx = suf[i];
        }
    }
    for (lol i = 0; i < n; i++)
    {
        cout << max(a[i], suf[op[i] + 1]) << " ";
    }
}