#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol d, s;
    cin >> d >> s;
    pair<lol, lol> x[d];
    lol min = 0, max = 0;
    for (lol i = 0; i < d; i++)
    {
        lol a, b;
        cin >> a >> b;
        min += a;
        max += b;

        x[i] = make_pair(a, b);
    }

    if (s >= min && s <= max)
    {
        cout << "YES" << endl;
        s -= min;

        lol i = 0;
        while (s > 0)
        {
            if (s <= x[i].second - x[i].first)
            {
                x[i].first = x[i].first + s;

                break;
            }
            else
            {

                s -= x[i].second - x[i].first;
                x[i].first = x[i].second;
            }
            i++;
        }
        for (lol i = 0; i < d; i++)
        {
            cout << x[i].first << " ";
        }
    }
    else
        cout << "NO" << endl;

    return 0;
}