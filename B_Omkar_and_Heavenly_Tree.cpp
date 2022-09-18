#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol n, m;
        cin >> n >> m;
        bool check[n];
        for (lol i = 0; i < n; i++)
        {
            check[i] = false;
        }

        while (m--)
        {
            lol a, b, c;
            cin >> a >> b >> c;
            check[b - 1] = true;
        }
        lol i;
        for (i = 0; i < n; i++)
        {
            if (!check[i])
            {
                break;
            }
        }
        while (n--)
        {
            if (n != i)
            {
                cout << n + 1 << " " << i + 1 << endl;
            }
        }
    }

    return 0;
}