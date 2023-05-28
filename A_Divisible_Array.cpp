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
        if (n % 2)
        {
            for (lol i = 0; i < n; i++)
            {
                cout << i + 1 << " ";
            }
            cout << '\n';
        }
        else
        {
            lol v = n - ((n * 1ll * (n + 1) / 2ll) % n);
            cout << v + 1 << " ";
            for (lol i = 1; i < n; i++)
            {
                cout << i + 1 << " ";
            }
            cout << '\n';
        }
    }

    return 0;
}