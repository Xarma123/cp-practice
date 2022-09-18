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
    lol k1;
    cin >> k1;
    queue<lol> q1;
    queue<lol> q2;

    for (lol i = 0; i < k1; i++)
    {
        lol q;
        cin >> q;
        q1.push(q);
    }
    lol k2;
    cin >> k2;

    for (lol i = 0; i < k2; i++)
    {
        lol q;
        cin >> q;
        q2.push(q);
    }
    lol ans = 0;
    while (q1.size() && q2.size())
    {
        ans++;
        if (ans >= 1e7)
        {
            ans = -1;
            break;
        }
        lol t1 = q1.front();
        lol t2 = q2.front();
        q1.pop();
        q2.pop();
        if (t1 > t2)
        {
            q1.push(t2);
            q1.push(t1);
        }
        else
        {
            q2.push(t1);
            q2.push(t2);
        }
    }

    cout << ans;
    if (q1.size() && ans != -1)
        cout << " 1";
    if (q2.size() && ans != -1)
        cout << " 2";

    return 0;
}