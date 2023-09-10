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
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        string s;
        cin >> s;
        lol v = 0;
        lol x = 0;
        lol p[n];
        for (lol i = 0; i < n; i++)
        {
            x ^= a[i];
            if (s[i] == '1')
                v ^= a[i];
            p[i] = a[i];
            if (i)
                p[i] ^= p[i - 1];
        }
        lol q;
        cin >> q;
        while (q--)
        {
            lol c;
            cin >> c;
            if (c == 2)
            {
                cin >> c;
                if (c == 0)
                {
                    cout << (x ^ v) << ' ';
                }
                else
                    cout << v << ' ';
            }
            else
            {
                lol l, r;
                cin >> l >> r;
                l--;
                r--;
                l--;
                v ^= p[r];
                if (l >= 0)
                    v ^= p[l];
            }
        }
        cout << '\n';
    }
}