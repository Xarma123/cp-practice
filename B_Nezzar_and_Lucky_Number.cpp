#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol q, d;
        cin >> q >> d;

        for (lol i = 0; i < q; i++)
        {
            lol t;
            cin >> t;
            bool f = false;
            while (t > 0)
            {
                lol c = t;
                while (c > 0)
                {
                    if (c % 10 == d)
                    {
                        f = true;
                        break;
                    }
                    c = c / 10;
                }
                if (f)
                    break;
                t -= d;
            }
            if (f)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
    }

    return 0;
}