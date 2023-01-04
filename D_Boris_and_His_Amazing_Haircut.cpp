#include <bits/stdc++.h>
#define lol long long
using namespace std;

vector<lol> nx(lol arr[], lol n)
{
    stack<pair<lol, lol>> s;
    s.push({arr[0], 0});
    vector<lol> nx(n);
    for (lol i = 1; i < n; i++)
    {

        if (s.empty())
        {
            s.push({arr[i], i});
            continue;
        }
        while (s.empty() == false && s.top().first < arr[i])
        {
            nx[s.top().second] = i;
            s.pop();
        }
        s.push({arr[i], -1});
    }
    while (s.empty() == false)
    {
        nx[s.top().second] = n;
        s.pop();
    }
    return nx;
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
        lol b[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        bool ans = true;
        for (lol i = 0; i < n; i++)
        {
            cin >> b[i];
            if (b[i] > a[i])
                ans = false;
        }
        vector<lol> nxg = nx(b, n);
        lol m;
        cin >> m;
        map<lol, lol> rzer;
        for (lol i = 0; i < m; i++)
        {
            lol q;
            cin >> q;
            rzer[q]++;
        }
        if (!ans)
            cout << "NO" << endl;
        else
        {
            map<lol, lol> us;
            lol i;
            for (i = 0; i < n; i++)
            {   
                if (a[i] > b[i] && us[b[i]] <= i)
                {
                    if (rzer.count(b[i]))
                    {
                        us[b[i]] = nxg[i];
                        rzer[b[i]]--;
                        if (rzer[b[i]] == 0)
                            rzer.erase(b[i]);
                    }
                    else
                        break;
                }
            }
            if (i == n)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
    }

    return 0;
}