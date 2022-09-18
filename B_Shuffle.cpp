#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol n, x, m;
        cin >> n >> x >> m;
        pair<lol, lol> s;
        s = make_pair(x , x );
        while (m--)
        {
            lol l, r;
            cin >> l >> r;
            if ((l <= s.second && l >= s.first) || (r <= s.second && r >= s.first)||(l<s.first&&r>s.second))
            {
                s.first = min(s.first, l );
                s.second = max(s.second, r );
            }
        }
        cout << s.second - s.first + 1 << endl;
    }

    return 0;
}