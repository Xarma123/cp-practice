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
        lol n;
        cin >> n;
        if (n == 1)
        {
            cout << "Yes" << '\n';
            cout << 1 << " " << 2 << '\n';
        }
        else if (n % 2 != 0)
        {
            cout << "Yes" << '\n';
            cout << 1 << " " << 2ll * n << '\n';
            lol l = 2 * n + 1 - n / 2;
            lol h = 2 * n + 2;
            for (lol i = 2; (l < 2 * n + 1 || h <= 2 * n + 1 + n / 2); i++)
            {
                if (i % 2 == 0)
                {
                    cout << i << " " << l - i << '\n';
                    l++;
                }
                else
                {
                    cout << i << " " << h - i << '\n';
                    h++;
                }
            }
        }
        else
            cout << "No" << '\n';
    }

    return 0;
}