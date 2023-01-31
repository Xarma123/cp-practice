#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n;
    cin >> n;
    vector<lol> sector[n + 1];
    vector<lol> thread[n + 1];
    for (lol i = 1; i <= n; i++)
    {
        lol k;
        cin >> k;
        while (k--)
        {
            lol p;
            cin >> p;
            sector[i].push_back(p);
            thread[i].push_back(p);
            if (i + 1 <= n)
                thread[i + 1].push_back(p);
            else
                thread[1].push_back(p);
        }
    }
    for (lol i = 1; i <= n; i++)
    {
        sort(sector[i].begin(), sector[i].end());
        sort(thread[i].begin(), thread[i].end());
    }
    lol ans = 0;
    for (lol i = 1; i <= n; i++)
    {
        for (lol j = 1; j < sector[i].size(); j++)
        {
            lol a = i, b = (i + 1) % n;
            if (i + 1 <= n)
                b = i + 1;
            else
                b = 1;
            lol x = upper_bound(thread[a].begin(), thread[a].end(), sector[i][j]) - thread[a].begin();
            lol y = upper_bound(thread[a].begin(), thread[a].end(), sector[i][j - 1] - 1) - thread[a].begin();
            lol xx = upper_bound(thread[b].begin(), thread[b].end(), sector[i][j]) - thread[b].begin();
            lol yy = upper_bound(thread[b].begin(), thread[b].end(), sector[i][j - 1] - 1) - thread[b].begin();
            if (x - y != xx - yy)
            {
                ans++;
               
            }
           
        }
    }
    cout << ans;

    return 0;
}