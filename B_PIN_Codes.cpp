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
        string a[n];
        set<string> x;
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
            x.insert(a[i]);
        }
        if (x.size() == n)
        {
            cout << 0 << endl;
            for (lol i = 0; i < n; i++)
            {
                cout << a[i] << endl;
            }
        }
        else
        {
            bool av[4][10];
            for (lol i = 0; i < 4; i++)
            {
                for (lol j = 0; j < 10; j++)
                {
                    av[i][j] = true;
                }
            }

            for (lol j = 0; j < 4; j++)
            {
                for (lol i = 0; i < n; i++)
                {
                    av[j][a[i][j] - '0'] = false;
                                }
            }
            x.clear();
            lol c = 0;
            for (lol i = 0; i < n; i++)
            {
                if (x.count(a[i]))
                {
                    lol j, k;

                    for (j = 0; j < 4; j++)
                    {
                        for (k = 0; k < 10; k++)
                        {
                            if (av[j][k])
                            {
                                av[j][k] = false;
                                break;
                            }
                        }
                        if (k != 10)
                            break;
                    }

                    a[i][j] = char(k + '0');
                    c++;
                }

                x.insert(a[i]);
            }
            cout << c << endl;
            for (lol i = 0; i < n; i++)
            {
                cout << a[i] << endl;
            }
        }
    }

    return 0;
}