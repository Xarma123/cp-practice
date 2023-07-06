#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol n, k, g;
        cin >> n >> k >> g;
        if (k * 1ll * g < (((g + 1) / 2) - 1) * 1ll * n)
        {
            cout << k * 1ll * g << endl;
        }
        else
        {
            lol s = (((g + 1) / 2) - 1);
            cout << k *1ll* g - ((((k *1ll* g - s *1ll* n + g - 1) / g) * g)) << '\n';
        }
    }
}