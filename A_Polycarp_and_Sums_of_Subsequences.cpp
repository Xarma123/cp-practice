#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol a[7];
        for (lol i = 0; i < 7; i++)
        {
            cin >> a[i];
        }
        cout << a[0] << " ";
        lol p = a[6] - a[0];
        bool f = false;
        for (lol i = 1; i < 6; i++)
        {
            lol check = p - a[i];
            for (lol j = 1; j < 6; j++)
            {
                if (j != i)
                {
                    if (a[j] == check)
                    {
                        cout << a[i] << " " << a[j] << endl;
                        f = true;
                        break;
                    }
                }
            }
            if (f)
                break;
        }
    }

    return 0;
}