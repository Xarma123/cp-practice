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
        lol a, b, c, d;
        cin >> a >> b >> c >> d;
        lol k = 4;
        bool ans = false;
        while (k--)
        {
            if (b > a && d > c && c > a && d > b)
            {
                ans = true;
            }
            lol na = c;
            lol nb = a;
            lol nc = d;
            lol nd = b;
            a = na;
            b = nb;
            c = nc;
            d = nd;
        }
        if (ans)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}