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
        lol p = 0, ne = 0;
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
            if (a[i] > 0)
                p++;
            else
                ne++;
        }
        lol c = 0;
        lol P = p;
        for (lol i = 0; i < n; i++)
        {
            if (P)
            {
                c++;
                P--;
            }
            else
                c--;
            cout << c << " ";
        }
        cout << '\n';
        c = 0;
        for (lol i = 0; i < n; i++)
        {
            if (i % 2 == 0)
            {
                c++;
            }
            else
            {
                if (ne)
                {
                    c--;
                    ne--;
                }
                else
                {
                    c++;
                }
            }
            cout << c << " ";
        }
        cout << '\n';
    }

    return 0;
}