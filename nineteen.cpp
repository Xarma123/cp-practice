#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    string a;
    cin >> a;
    lol n = 0, i = 0, e = 0, t = 0;
    for (lol j = 0; j < a.size(); j++)
    {
        if (a[j] == 'n')
            n++;
        if (a[j] == 'i')
            i++;

        if (a[j] == 'e')
            e++;
        if (a[j] == 't')
            t++;
    }

    if (n == 0 || i == 0 || e == 0 || t == 0)
    {
        cout << 0;
    }
    else
    {
        if ( e / 3 != 0)
        {
            lol x = min(e / 3, min(i, t));
        a:
            if (n >= 2 * x + 1)
            {
                cout <<x;
            }
            else
            {
                x--;
                goto a;
            }
        }
        else
        {
            cout << 0;
        }
    }

    return 0;
}