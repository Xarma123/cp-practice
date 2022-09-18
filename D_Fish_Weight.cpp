#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol n, m, k;
    cin >> n >> m >> k;
    map<lol, lol> Alice;
    for (lol i = 0; i < n; i++)
    {
        lol t;
        cin >> t;
        Alice[t]++;
    }
    map<lol, lol> Bob;
    for (lol i = 0; i < m; i++)
    {
        lol t;
        cin >> t;
        Bob[t]++;
    }
    if ((*Alice.rbegin()) > (*Bob.rbegin()))
    {
        cout << "YES";
    }

    else
    {
        lol w = 1;
        lol al = 0, bo = 0;
        auto it1 = Alice.begin();
        auto it2 = Bob.begin();
        while (it1 != Alice.end() && it2 != Bob.end())
        {
            if ((*it1).first <= (*it2).first)
            {
                if ((*it1).second <= (*it2).second)
                {
                    al += (*it1).second * w;
                    bo += (*it2).second * w;
                }
                else
                {
                    w++;
                    al += (*it1).second * w;
                    bo += (*it2).second * w;
                }
            }
            else
            {
                if ((*it1).second <= (*it2).second)
                {
                    al += (*it1).second * ((*it2).second * w);
                    bo += (*it2).second * w;
                    w = ((*it2).second * w);
                }
                else
                {
                    bo += (*it2).second * w;
                    w++;
                    al += (*it1).second * w;
                }
            }
            it1++;
            it2++;
        }
        while (it1 != Alice.end())
        {
            w++;
            al += (*it1).second * w;
            it1++;
        }
        while (it2 != Bob.end())
        {

            bo += (*it2).second * w;
            it2++;
        }
        if (al > bo)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}