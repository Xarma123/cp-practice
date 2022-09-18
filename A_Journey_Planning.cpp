#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol n;
    cin >> n;
    lol b[n];
    map<lol, priority_queue<lol>> mp;
    for (lol i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    lol ans[n];

    for (lol i = 0; i < n; i++)
    {
        ans[i] = b[i];
        lol c = 0;
        if (mp.count(b[i] - i))
        {
            c = mp[b[i] - i].top();
        }
        ans[i] += c;
        mp[b[i] - i].push(ans[i]);
    }
    lol q = LONG_LONG_MIN;
    for (lol i = 0; i < n; i++)
    {
        q = max(q, ans[i]);
    }
    cout << q << endl;

    return 0;
}