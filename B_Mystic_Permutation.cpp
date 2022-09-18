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
        if (n == 1)
        {
            for (lol i = 0; i < n; i++)
            {
                lol q;
                cin >> q;
            }
            cout << -1 << endl;
            continue;
        }
        priority_queue<lol, vector<lol>, greater<lol>> q;
        lol a[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
            q.push(a[i]);
        }
        lol ans[n];
        for (lol i = 0; i < n; i++)
        {
            if (q.top() != a[i])
            {
                ans[i] = q.top();
                q.pop();
            }
            else
            {
                q.pop();
                if (!q.empty())
                {
                    ans[i] = q.top();
                    q.pop();
                    q.push(a[i]);
                }
                else
                {
                    ans[i] = a[i];
                }
            }
        }
        if (ans[n - 1] == a[n - 1])
        {
            swap(ans[n - 2], ans[n - 1]);
        }
        for (lol i = 0; i < n; i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
    }

    return 0;
}