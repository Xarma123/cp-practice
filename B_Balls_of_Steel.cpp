#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol n, k;
        cin >> n >> k;
        vector<pair<lol, lol>> p;
        for (lol i = 0; i < n; i++)
        {
            lol x, y;
            cin >> x >> y;

            p.push_back(make_pair(x, y));
        }
        lol i;
        for (i = 0; i < n; i++)
        {
            lol j;
            for (j = 0; j < n; j++)
            {
                if (j != i)
                {
                    if ((abs(p[i].first - p[j].first) + abs(p[i].second - p[j].second)) > k)
                        break;
                }
            }
            if (j == n)
                break;
        } 
        if(i==n)
        cout<<-1<<endl;
        else
        cout<<1<<endl;
    }

    return 0;
}