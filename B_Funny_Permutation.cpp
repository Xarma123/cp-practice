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
        if (n % 2 == 0)
        {
            for (lol i = n; i >= 1; i--)
            {
                cout << i << " ";
            }
            cout << endl;
        }
        else if (n == 3)
            cout << -1 << endl;
        else
        {
            for (lol i = n; i > n / 2 + 1; i--)
            {
                cout << i << " ";
            }
            for (lol i = 1; i <= n / 2 + 1; i++)
            {
                cout << i << " ";
            }
            cout << endl;
        }
    }

    return 0;
}