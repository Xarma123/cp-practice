#include <bits/stdc++.h>
#define lol long long
using namespace std;
bitset<500001> p;
int main()
{
    lol n;
    cin >> n;
    p[0] = 1;
    p[1] = 1;
    for (lol i = 2; i * i <= 2 * n; i++)
    {
        if (p[i] == 0)
        {
            for (lol j = i * i; j <= 2 * n; j += i)
            {
                p[j] = 1;
            }
        }
    }
    lol t2 = 0, o1 = 0;
    for (lol i = 0; i < n; i++)
    {
        lol t;
        cin >> t;
        if (t == 2)
            t2++;
        else
            o1++;
    }
    lol v = 0;
    for (lol i = 1; i <= n; i++)
    {
        if (o1)
        {
            if (p[v + 1] == 0)
            {
                cout << 1 << " ";
                v++;
                o1--;
            }
            else
            {
                if (t2)
                {
                    cout << 2 << " ";
                    v += 2;
                    t2--;
                }
                else
                {
                    cout << 1 << " ";
                    v++;
                    o1--;
                }
            }
        }
        else
        {
            cout << 2 << " ";
            v += 2;
            t2--;
        }
    }

    return 0;
}