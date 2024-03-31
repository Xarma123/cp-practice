#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol t;
    cin >> t;
    while (t--)
    {
        lol n;
        cin >> n;
        lol a[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        sort(a, a + n);
        lol i;
        for (i = 0; i < n && a[i] == a[0]; i++)
        {
            /* code */
        }
        if (i ==1)
        {
            cout << "YES\n";
        }
        else
        {
            for (; i < n && a[i] % a[0] == 0; i++)
            {
                // pass
            }
            if (i == n)
                cout << "NO\n";
            else
                cout << "YES\n";
        }
    }

    return 0;
}
