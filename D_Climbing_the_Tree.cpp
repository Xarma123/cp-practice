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
        lol q;
        cin >> q;
        lol mn = 1;
        lol mx = LONG_LONG_MAX;
        while (q--)
        {
            lol c;
            cin >> c;
            if (c == 1)
            {
                lol a, b, n;
                cin >> a >> b >> n;
                lol l, r;
                if (n == 1)
                {
                    l = 0, r = a;
                }
                else
                {
                    l = (a - b) * 1ll * (n - 1) + b + 1;
                    r = (a - b) * 1ll * (n - 1) + a;
                }
                if (l > mx || r < mn)
                {
                    cout << 0 << ' ';
                }
                else
                {
                    cout << 1 << ' ';
                    mn = max(mn, l);
                    mx = min(mx, r);
                }
               
            }
            else
            {
                lol a, b;
                cin >> a >> b;
                lol q1;
                if (mn <= a)
                {
                    q1 = 1;
                }
                else
                {
                    q1 = (long long)(ceill((mn - a) / (long double)(a - b)) + 1);
                }
                swap(mn, mx);
                lol q2;
                if (mn <= a)
                {
                    q2 = 1;
                }
                else
                {
                    q2 = (long long)(ceill((mn - a) / (long double)(a - b)) + 1);
                }
                swap(mn, mx);
                if (q1 == q2)
                    cout << q1 << " ";
                else
                    cout << -1 << " ";
            }
        }
        cout << '\n';
    }

    return 0;
}