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
        if (n % 2 != 0)
        {
            for (lol i = n - (n - 1) / 2 + 2; i <= n + (n - 1) / 2 + 2; i++)
            {
                if (i == n - (n - 1) / 2 + 2)
                    cout << i - 1 << " ";
                else if (i == n + (n - 1) / 2 + 2)
                    cout << i + 1 << " ";
                else if (i == n + (n - 1) / 2 + 1)
                    cout << i + 1 << " ";
                else
                    cout << i << " ";
            }
        }
        else
        {
            for (lol i = n - n / 2; i <= n + n / 2; i++)
            {
                if (i != n)
                    cout << i << " ";
            }
        }
        cout << '\n';
    }

    return 0;
}