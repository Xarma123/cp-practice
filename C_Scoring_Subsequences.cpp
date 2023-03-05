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
        for (lol i = 0; i < n; i++)
        {
            lol st = -1, e = i + 1;
            while (st != e - 1)
            {
                lol m = (st + e) / 2;
                if (m == i + 1)
                {
                    e = m;
                }
                else if (m == -1)
                {
                    st = m;
                }
                else
                {
                    if (a[m] >= i - m + 1)
                    {
                        e = m;
                    }
                    else
                        st = m;
                }
            }
            cout << i - e + 1 << " ";
        }
        cout << '\n';
    }

    return 0;
}