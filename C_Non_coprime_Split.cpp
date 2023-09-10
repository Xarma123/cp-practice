#include <bits/stdc++.h>
using namespace std;
#define lol long long
lol p[10000005];
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
  

    for (lol i = 2; i < 10000005; i++)
    {
        if (p[i] == 0)
        {
            for (lol j = i * 1ll * i; j < 10000005; j += i)
            {
                p[j] = i;
            }
        }
    }
    lol t;
    cin >> t;
    while (t--)
    {
        lol l, r;
        cin >> l >> r;
        lol i;
        for (i = l; i <= r; i++)
        {
            if (p[i] != 0)
            {
                cout << i - p[i] << " " << p[i] << '\n';
                break;
            }
        }
        if (i > r)
            cout << -1 << '\n';
    }
}