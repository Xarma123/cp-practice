#include <bits/stdc++.h>
using namespace std;
#define lol long long

int main()
{
    lol pw[10];
    pw[0] = 1;
    for (lol i = 1; i < 10; i++)
    {
        pw[i] = pw[i - 1] * 10ll;
    }

    lol t;
    cin >> t;
    while (t--)
    {
        lol a, b, c, k;
        cin >> a >> b >> c >> k;

        lol a1 = pw[a - 1];
        if (a1 == 0)
            a1++;
        lol c1 = pw[c - 1];
        if (c1 == 0)
            c1++;
        lol b1 = pw[b - 1];
        if (b1 == 0)
            b1++;
        lol tot = 0;
        for (lol i = a1; i < pw[a]; i++)
        {
            lol l = max(b1, c1 - i);
            lol r = min(pw[c] - 1 - i, pw[b] - 1);

            if (l > r)
                continue;
            if (tot + r - l + 1 >= k)
            {
                lol j = l + k - tot - 1;
                tot = k;
                cout << i << " + " << j << " = " << i + j << '\n';
                break;
            }
            else
                tot += r - l + 1;
        }
        if (tot != k)
            cout << -1 << '\n';
    }
}