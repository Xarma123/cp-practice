#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol t;
    cin >> t;
    while (t--)
    {
        lol n, k;
        cin >> n >> k;
        lol a[n + 1];
        lol ind[n + 1];
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i + 1];
            ind[i + 1] = 0;
        }
        if (k == 1)
        {
            bool ans = true;
            for (lol i = 1; i <= n; i++)
            {
                if (i != a[i])
                    ans = false;
            }
            if (ans)
                cout << "YES\n";
            else
                cout << "NO\n";
            continue;
        }
        for (lol i = 1; i <= n; i++)
        {
            ind[a[i]]++;
        }
        queue<lol> q;
        for (lol i = 1; i <= n; i++)
        {
            if (ind[i] == 0)
                q.push(i);
        }
        while (!q.empty())
        {
            lol v = q.front();
            q.pop();
            if (--ind[a[v]] == 0)
            {
                q.push(a[v]);
            }
        }
        bool ans = true;
        for (lol i = 1; i <= n; i++)
        {
            if (ind[i])
            {
                lol c = 1;
                ind[i] = 0;
                lol j = a[i];
                while (ind[j])
                {
                    c++;
                    ind[j] = 0;
                    j = a[j];
                }
                if (c - k != 0)
                    ans = false;
            }
        }
        if (ans)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}