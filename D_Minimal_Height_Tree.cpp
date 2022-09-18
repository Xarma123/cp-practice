#include <bits/stdc++.h>
#define lol long long
using namespace std;
lol ans = LONG_LONG_MIN;
void height(map<lol, vector<lol>> &mp, lol s, lol lvl)
{

    for (lol i = 0; i < mp[s].size(); i++)
    {
        height(mp, mp[s][i], lvl + 1);
    }
    ans = max(ans, lvl);
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol t;
    cin >> t;
    while (t--)
    {
        lol n;
        cin >> n;
        lol a[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        map<lol, vector<lol>> mp;
        queue<lol> q;
        q.push(1);
        lol p = 1;
        lol papa = 1;
        lol last = -1;
        while (1)
        {
            if (a[p] > last)
            {
                q.push(a[p]);
                mp[papa].push_back(a[p]);

                last = a[p];
                p++;
            }
            else
            {
                q.pop();
                papa = q.front();
                mp[papa].push_back(a[p]);
                q.push(a[p]);
                last = a[p];
                p++;
            }
            if (p == n)
                break;
        }
        height(mp, 1, 0);

        cout << ans << endl;
        ans = LONG_LONG_MIN;
    }

    return 0;
}