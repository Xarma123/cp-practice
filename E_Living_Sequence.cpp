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
        lol pw[15];
        for (lol i = 0; i < 15; i++)
        {
            if (i == 0)
                pw[i] = 1;
            else
                pw[i] = pw[i - 1] * 9ll;
        }

        lol s = 0, e = 14;
        while (s != e - 1)
        {
            lol m = (s + e) / 2;
            if (pw[m] - 1 >= k)
                e = m;
            else
                s = m;
        }

        k -= pw[e - 1] - 1;

        for (lol i = 0; i < e; i++)
        {
            lol c = ceill(k / (long double)pw[e - i - 1]);
            if (i == 0)
            {
                if (c > 3)
                    cout << c + 1;
                else
                    cout << c;
            }
            else
            {
                if (c <= 4)
                    cout << c - 1;
                else
                    cout << c;
            }
            k -= (c - 1) * 1ll * pw[9ll, e - i - 1];
        }
        cout << '\n';
    }

    return 0;
}