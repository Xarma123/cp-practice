#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    while (1)
    {
        lol n, m;
        cin >> n >> m;
        if (n == 0 && m == 0)
            break;
        map<lol, vector<lol>> mp;
        map<lol, lol> ind;
        while (m--)
        {
            lol a, b;
            cin >> a >> b;
            mp[a].push_back(b);
            ind[b]++;
        }
        queue<lol> q;
        for (lol i = 1; i <= n; i++)
        {
            if (ind[i] == 0)
            {
                q.push(i);
            }
        }
        while (!q.empty())
        {
            cout << q.front() << " ";
            for (auto e : mp[q.front()])
            {
                ind[e]--;
                if (ind[e] == 0)
                    q.push(e);
            }
            q.pop();
        }
        cout << endl;
    }

    return 0;
}