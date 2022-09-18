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
        lol a[n];
        bool ten = false;
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        for (lol i = 0; i < n; i++)
        {
            if (a[i] % 10 == 5)
            {
                a[i] = a[i] + a[i] % 10;
            }
            if (a[i] % 10 == 0)
                ten = true;
        }
        if (ten)
        {
            lol i;
            for (i = 1; i < n; i++)
            {
                if (a[i] != a[0])
                {
                    cout << "NO" << endl;
                    break;
                }
            }
            if (i == n)
                cout << "YES" << endl;
        }
        else
        {
            for (lol i = 0; i < n; i++)
            {
                while (a[i] % 10 != 2)
                    a[i] += a[i] % 10;
            }
            sort(a, a + n);
            lol i;
            for (i = 0; i < n; i++)
            {
                if ((a[n - 1] - a[i]) % 20 != 0)
                {
                    cout << "NO" << endl;
                    break;
                }
            }
            if (i == n)
                cout << "YES" << endl;
        }
    }

    return 0;
}