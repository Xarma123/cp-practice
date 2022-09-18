#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol n;
        cin >> n;
        lol a[n + 1];
        for (lol i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        lol c = 0;
        for (lol i = 1; i <= n; i++)
        {
            for (lol j = a[i] - i; j <= n; j+=a[i])
            {
                if (j > 0)
                {
                    if (a[i] * a[j] == i + j && i < j)
                    {
                        c++;
                    }
                }
            }
        }
        cout << c << endl;
    }

    return 0;
}