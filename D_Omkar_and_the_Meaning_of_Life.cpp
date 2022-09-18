#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    lol n;
    cin >> n;
    map<lol, lol> mp;
    lol root;
    for (lol i = n; i >= 1; i--)
    {
        cout.flush() << "? ";
        for (lol j = 1; j <= n; j++)
        {
            if (j != i)
            {
                if (j == n)
                    cout.flush() << 1;
                else
                    cout.flush() << 1 << " ";
            }
            else
            {
                if (j == n)
                    cout.flush() << 2;
                else
                    cout.flush() << 2 << " ";
            }
        }
        cout.flush() << endl;
        lol ans;
        cin >> ans;
        if (ans == 0)
            root = i;
        else if (ans != i)
            mp[ans] = i;
        cout.flush() << "? ";
        for (lol j = 1; j <= n; j++)
        {
            if (j != i)
            {
                if (j == n)
                    cout.flush() << 2;
                else
                    cout.flush() << 2 << " ";
            }
            else
            {
                if (j == n)
                    cout.flush() << 1;
                else
                    cout.flush() << 1 << " ";
            }
        }
        cout.flush() << endl;

        cin >> ans;
        if (ans != i && ans != 0)
            mp[i] = ans;
    }

    vector<lol> q(n, 0);
    vector<bool> vis(n, false);
    while (root != 0 && !vis[root - 1])
    {
        vis[root - 1] = true;
        q[root - 1] = n;
        n--;

        root = mp[root];
    }
    cout.flush() << "! ";
    for (auto e : q)
    {
        cout.flush() << e << " ";
    }
    cout.flush() << endl;

    return 0;
}