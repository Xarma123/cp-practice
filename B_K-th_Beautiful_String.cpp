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
        string a;
        for (lol i = 0; i < n; i++)
        {
            a.push_back('a');
        }

        lol k;
        cin >> k;
        lol l = ceill((sqrtl((1 + 8 * 1ll * k)) - 1) / (long double)2);
        a[n - l - 1] = 'b';
        a[n - (k - (l * 1ll * (l - 1) / 2) - 1) - 1] = 'b';
        cout << a << endl;
    }
    return 0;
}