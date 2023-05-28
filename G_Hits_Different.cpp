#include <bits/stdc++.h>
#define lol long long
using namespace std;
lol n = 2023;
lol a[4092530];
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    a[1] = 1;
    lol v = 2;
    for (lol i = 2; i <= n; i++)
    {
        for (lol j = v; j < v + i; j++)
        {
            if (j == v)
            {
                a[j] = j * 1ll * j + a[j - i + 1];
            }
            else if (j == v + i - 1)
            {
                a[j] = j * 1ll * j + a[j - i];
            }
            else
            {
                a[j] = j * 1ll * j + a[j - i + 1] + a[j - i] - a[j - i - (i - 2)];
            }
           
        }
     
        v += i;
    }
    lol t;
    cin >> t;
    while (t--)
    {
        lol c;
        cin >> c;
        cout << a[c] << '\n';
    }

    return 0;
}