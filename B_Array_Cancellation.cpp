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
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        lol s = 0;
        for (lol i = 0; i < n; i++)
        {
            if (a[i] >= 0)
                s += a[i];
            else
            {
                if (s + a[i] >= 0)
                    s += a[i];
                else
                    s = 0;
            }
        }
        cout << s << endl;
    }

    return 0;
}