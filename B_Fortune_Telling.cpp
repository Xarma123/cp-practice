#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol n, x, y;
        cin >> n >> x >> y;
        lol a[n];
        lol o = 0, e = 0;
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
            if (a[i] % 2 == 0)
                e++;
            else
                o++;
        }

        if (y % 2 == 0)
        {
            if (o % 2 == 0)
            {
                if (x % 2 == 0)
                    cout << "Alice" << endl;
                else
                    cout << "Bob" << endl;
            }
            else
            {
                if (x % 2 != 0)
                    cout << "Alice" << endl;
                else
                    cout << "Bob" << endl;
            }
        }
        else
        {
            if (o % 2 == 0)
            {
                if (x % 2 != 0)
                    cout << "Alice" << endl;
                else
                    cout << "Bob" << endl;
            }
            else
            {
                if (x % 2 == 0)
                    cout << "Alice" << endl;
                else
                    cout << "Bob" << endl;
            }
        }
    }

    return 0;
}