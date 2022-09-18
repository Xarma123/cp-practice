#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol a, b;
        cin >> a >> b;
        string map;
        cin >> map;
        lol c = 1;
        lol cost = 0;
        lol prv;
        for (lol i = 0; i < map.size(); i++)
        {
            if (map[i] == '1')
            {
                if (c == 1)
                {
                    cost += a;
                    c++;
                    lol k = i;
                    while (1)
                    {
                        if (map[k] == '1')
                            k++;
                        else
                            break;
                        if (k == map.size())
                            break;
                    }
                    if (k == map.size())
                        break;
                    prv = k;
                    i = k - 1;
                }
                else
                {
                    if (cost + a <= cost + b * (i - prv))
                    {
                        cost += a;
                    }
                    else
                        cost += b * (i - prv);
                    lol k = i;
                    while (1)
                    {
                        if (map[k] == '1')
                            k++;
                        else
                            break;
                        if (k == map.size())
                            break;
                    }
                    if (k == map.size())
                        break;
                    prv = k;
                    i = k - 1;
                }
            }
        }
        cout << cost << endl;
    }

    return 0;
}