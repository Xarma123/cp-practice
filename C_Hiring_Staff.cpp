#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, m, k;
    cin >> n >> m >> k;
    if (n >= m + 2)
    {
        cout << 2ll * k << endl;
        for (lol i = 0; i < k; i++)
        {
            cout << 1 << " ";
        }
        for (lol i = 0; i < k; i++)
        {
            cout << n << " ";
        }
    }
    else if (n == m + 1)
    {
        if (k == 1)
        {
            cout << 3 << endl;
            cout << 1 << " " << n << " " << n + 1;
        }
        else
        {
            cout << 2ll * k << endl;
            for (lol i = 0; i < k; i++)
            {
                cout << 1 << " ";
            }
            cout << n << " ";
            for (lol i = 1; i < k; i++)
            {
                cout << n + 1 << " ";
            }
        }
    }
    else
    {
        if (n == 2 && k == 1)
            cout << 2ll * k + 2 << endl;
        else
            cout << 2ll * k + 1 << endl;
        for (lol i = 0; i < k; i++)
        {
            cout << 1 << " ";
        }
        cout << n << " ";
        for (lol i = 0; i < k - 1; i++)
        {
            cout << n + 1 << " ";
        }
        if (n == 2 && k == 1)
            cout << n + 1 << " ";
        cout << n + 2 << " ";
    }

    return 0;
}