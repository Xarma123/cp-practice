#include <bits/stdc++.h>
#define lol long long
using namespace std;
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
        lol b[n];
        lol ans[n];
        priority_queue<pair<lol, lol>> q;
        for (lol i = 0; i < n; i++)
        {
            cin >> b[i];
            lol v = b[i] + 1;
            q.push({(i + 1) / v + 1, (-i)});
        }
        for (lol i = n; i > 0; i--)
        {
            ans[(-q.top().second)] = i;
            q.pop();
        }
        for (lol i = 0; i < n; i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
    }

    return 0;
}