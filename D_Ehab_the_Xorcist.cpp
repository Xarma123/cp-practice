#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol u, v;
    cin >> u >> v;
    if (u == v)
    {
        if (u)
        {
            cout << 1 << endl;
            cout << u;
        }
        else
            cout << 0;
    }
    else if (v >= u && ((u % 2) == (v % 2)))
    {
        lol x = v - u;
        lol a = u, b = 0, c = 0;
        for (lol i = 0; i < 64; i++)
        {
            if ((x & (1ll << i)))
            {
                if ((a & (1ll << (i - 1))))
                {
                    b |= (1ll << (i - 1));
                    c |= (1ll << (i - 1));
                }
                else
                {
                    b |= (1ll << (i - 1));
                    a |= (1ll << (i - 1));
                }
            }
        }
        if (c == 0)
        {
            cout << 2 << endl;
            cout << a << " " << b;
        }
        else
        {
            cout << 3 << endl;
            cout << a << " " << b << " " << c;
        }
    }
    else
        cout << -1;

    return 0;
}