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
        lol x, k;
        cin >> x >> k;
        string s = to_string(x);
        lol ans = 0;
        for (auto e : s)
        {
            ans += (e - '0');
        }
        if (ans % k == 0)
            cout << s << '\n';
        else
        {
            lol r = k - (ans % k);
            if (r + (s.back() - '0') < 10ll)
            {
                x += r;
                cout << x << '\n';
            }
            else
            {
                x /= 10;
                x++;
                x *= 10ll;
                ans = 0;
                s = to_string(x);
                for (auto e : s)
                {
                    ans += (e - '0');
                }
                r = k - (ans % k);
                if (r != k)
                    x += r;
                cout << x << '\n';
            }
        }
    }

    return 0;
}
