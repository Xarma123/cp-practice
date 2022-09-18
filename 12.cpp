#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol t;
    cin >> t;
    for (lol k = 1; k <= t; k++)
    {
        string I, p;
        cin >> I >> p;
        lol j = 0;
        for (lol i = 0; i < p.size(); i++)
        {
            if (j == I.size())
                break;
            if (I[j] == p[i])
                j++;
        }
        if (j == I.size())
            cout << "Case #" << k << ": " << p.size() - I.size() << endl;
        else
            cout << "Case #" << k << ": "
                 << "IMPOSSIBLE" << endl;
    }

    return 0;
}