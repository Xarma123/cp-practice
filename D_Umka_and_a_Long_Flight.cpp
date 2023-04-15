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
        lol k;
        cin >> k;
        lol s = 0, e = 14;
        while (s != e - 1)
        {
            lol m = (s + e) / 2;
            if (powl(9, m) - 1 >= k)
                e = m;
            else
                s = m;
        }
        k -= powl(9, e - 1) - 1;
        for (lol i = 0; i < e; i++)
        {
            lol c = k / powl(9, e - i - 1);
            if (c > 3)
                cout << c + 1;
            else
                cout << c;
            k -= (c - 1) * 1ll * powl(9, e - i - 1);
        }
        cout << '\n';
    }

    return 0;
}