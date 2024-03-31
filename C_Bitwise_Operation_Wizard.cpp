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
        lol n;
        cin >> n;
        lol a[n];
        memset(a, 0, sizeof(a));
        for (lol i = 0; i < n; i++)
        {
            for (lol j = 0; j < n; j++)
            {
                if (i != j)
                {
                    cout << "? " << i << " " << i << " " << j << " " << j << endl;
                    char c;
                    cin >> c;
                    if (c == '>')
                        a[i]++;
                }
            }
        }
        lol v = n - 1;
        bool z = false;
        for (lol i = 31; i >= 0; i--)
        {
            if (z)
            {
                v ^= (1ll << i);
            }
            else if ((v & (1ll << i)))
            {
                z = true;
                v ^= (1ll << i);
            }
        }
        lol x1, x2;
        for (lol i = 0; i < n; i++)
        {
            if (a[i] == n - 1)
            {
                x1 = i;
            }
            else if (a[i] == v)
                x2 = i;
        }
        cout << "! " << x1 << " " << x2 << endl;
    }

    return 0;
}
