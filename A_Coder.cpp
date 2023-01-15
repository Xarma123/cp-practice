#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n;
    cin >> n;
    cout << (n / 2) * 1ll * (n / 2) + ceill(n / (long double)2) * 1ll * ceill(n / (long double)2) << endl;
    for (lol i = 0; i < n; i++)
    {
        for (lol j = 0; j < n; j++)
        {
            if ((i % 2 == 0))
            {
                if (j % 2 == 0)
                    cout << 'C';
                else
                    cout << '.';
            }
            else
            {
                if (j % 2 == 0)
                    cout << '.';
                else
                    cout << 'C';
            }
        }
        cout << endl;
    }

    return 0;
}