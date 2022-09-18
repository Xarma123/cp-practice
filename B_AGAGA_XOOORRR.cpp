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
        lol a[n];
        lol s = 0;
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
            s = s ^ a[i];
        }
        lol i;
        lol q = 0;
        for (i = 0; i < n - 1; i++)
        {
            q = q ^ a[i];
            if (q == (s ^ q))
                break;
        }
        if (i == n - 1)
        {
            q = 0;
            for (i = 0; i < n - 2; i++)
            {
                q = q ^ a[i];
                lol till = q;
                lol q2 = 0;
                lol j;
                for (j = i + 1; j < n - 1; j++)
                {
                    till = till ^ a[j];
                    q2 = q2 ^ a[j];
                    if (q2 == q && (s ^ till) == q)
                    {
                        break;
                    }
                }
                if (j < n - 1)
                    break;
            }
            if (i < n - 2)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
        else
            cout << "YES" << endl;
    }

    return 0;
}