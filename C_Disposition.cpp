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
    if (n % 2 == 0)
    {
        for (lol i = 1; i <= n; i++)
        {
            if (i % 2 == 0)
            {
                cout << 1 + i - 2 << " ";
            }
            else
            {
                cout << 2 + i - 1 << " ";
            }
        }
    }
    else
    {
        cout << 1 << " ";
        for (lol i = 2; i <= n; i++)
        {
            if (i % 2 == 0)
            {
                cout << 3 + i - 2 << " ";
            }
            else
            {
                cout << 2 + i - 3 << " ";
            }
        }
    }

    return 0;
}