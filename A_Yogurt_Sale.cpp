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
        lol n, a, b;
        cin >> n >> a >> b;

        if ((long double)a > (long double)(b / (long double)2))
        {
            if (n % 2 == 0)
            {
                cout << (b * 1ll * (n / 2ll)) << '\n';
            }
            else
            {
                cout << (b * 1ll * (n / 2ll)) + a << '\n';
            }
        }
        else
        {
            cout << n * 1ll * a << '\n';
        }
    }

    return 0;
}
