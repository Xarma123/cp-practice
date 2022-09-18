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
        lol a[n][5];
        for (lol i = 0; i < n; i++)
        {
            for (lol j = 0; j < 5; j++)
            {
                cin >> a[i][j];
            }
        }
        map<lol, lol> winner;
        for (lol i = 0; i < 5; i++)
        {
            lol ind = 0;
            for (lol j = 1; j < n; j++)
            {
                if (a[j][i] < a[in][i])
                {
                    ind = j;
                }
            }
            winnner[ind]++;
        }
        bool f = false;
        for (auto i = winnner.begin(); i != winnner.end(); i++)
        {
            if( (*i) >=3)
            {
                
            }
        }
    }

    return 0;
}