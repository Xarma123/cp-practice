#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol n;
        cin >> n;
        lol c1 = 0, c0 = 0;
        lol a[n];

        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];

            if (a[i] == 1)
                c1++;
            else if (a[i] == 0)
                c0++;
        }
        sort(a, a + n);
        if (c0 != 0 && c1 != 0)
            cout << "NO" << endl;
        else if (c1 != 0)
        {
            bool ans = true;
            for (lol i = 0; i < n - 1; i++)
            {
                if (a[i + 1] - a[i] == 1)
                    ans = false;
            }
            if (ans)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
        else
            cout << "YES" << endl;
    }

    return 0;
}