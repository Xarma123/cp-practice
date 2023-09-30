#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n;
    cin >> n;
    vector<vector<lol>> q;
    lol f[n + 1];
    memset(f, 0, sizeof(f));
    for (lol i = 0; i < n - 2; i++)
    {
        vector<lol> a(3);
        cin >> a[0] >> a[1] >> a[2];
        f[a[0]]++;
        f[a[1]]++;
        f[a[2]]++;
        q.push_back(a);
    }
    lol a1;
    lol a2, a3;
    lol a4;
    lol a5 = -1;
    for (lol i = 1; i <= n; i++)
    {
        if (f[i] == 1)
        {
            a1 = i;
            break;
        }
    }
    for (lol i = 0; i < n - 2; i++)
    {
        if (q[i][0] == a1 || q[i][1] == a1 || q[i][2] == a1)
        {

            if (q[i][0] == a1)
            {
                a2 = q[i][1];
                a3 = q[i][2];
            }
            if (q[i][1] == a1)
            {
                a2 = q[i][0];
                a3 = q[i][2];
            }
            if (q[i][2] == a1)
            {
                a2 = q[i][0];
                a3 = q[i][1];
            }

            for (auto e : q)
            {
                if ((e[0] == a2 && e[1] == a3) || (e[0] == a3 && e[1] == a2))
                {
                    if (e[2] != a1)
                        a4 = e[2];
                }
                if ((e[0] == a2 && e[2] == a3) || (e[0] == a3 && e[2] == a2))
                {
                    if (e[1] != a1)
                        a4 = e[1];
                }
                if ((e[1] == a2 && e[2] == a3) || (e[1] == a3 && e[2] == a2))
                {
                    if (e[0] != a1)
                        a4 = e[0];
                }
            }
            for (auto e : q)
            {
                if ((e[0] == a2 && e[1] == a4) || (e[0] == a4 && e[1] == a2))
                {
                    if (e[2] != a3)
                    {
                        swap(a2, a3);
                        a5 = e[2];
                    }
                }
                if ((e[0] == a2 && e[2] == a4) || (e[0] == a4 && e[2] == a2))
                {
                    if (e[1] != a3)
                    {
                        swap(a2, a3);
                        a5 = e[1];
                    }
                }
                if ((e[1] == a2 && e[2] == a4) || (e[1] == a4 && e[2] == a2))
                {
                    if (e[0] != a3)
                    {
                        swap(a2, a3);
                        a5 = e[0];
                    }
                }
            }
            if (a5 == -1)
            {
                for (auto e : q)
                {
                    if ((e[0] == a3 && e[1] == a4) || (e[0] == a4 && e[1] == a3))
                    {
                        if (e[2] != a2)
                        {

                            a5 = e[2];
                        }
                    }
                    if ((e[0] == a3 && e[2] == a4) || (e[0] == a4 && e[2] == a3))
                    {
                        if (e[1] != a2)
                        {

                            a5 = e[1];
                        }
                    }
                    if ((e[1] == a3 && e[2] == a4) || (e[1] == a4 && e[2] == a3))
                    {
                        if (e[0] != a2)
                        {

                            a5 = e[0];
                        }
                    }
                }
            }

            break;
        }
    }
    lol ans[n];
    ans[0] = a1;
    ans[1] = a2;
    ans[2] = a3;
    ans[3] = a4;
    ans[4] = a5;
    map<lol, map<lol, vector<lol>>> mp;
    for (auto e : q)
    {
        mp[e[0]][e[1]].push_back(e[2]);
        mp[e[0]][e[2]].push_back(e[1]);
        mp[e[1]][e[0]].push_back(e[2]);
        mp[e[1]][e[2]].push_back(e[0]);
        mp[e[2]][e[0]].push_back(e[1]);
        mp[e[2]][e[1]].push_back(e[0]);
    }
    set<lol> x;
    x.insert(a1);
    x.insert(a2);
    x.insert(a3);
    x.insert(a4);
    x.insert(a5);
    for (lol i = 5; i < n; i++)
    {
        lol v = mp[ans[i - 1]][ans[i - 2]][0];
        if (x.count(v))
            v = mp[ans[i - 1]][ans[i - 2]][1];
        ans[i] = v;
        x.insert(v);
    }
    for (lol i = 0; i < n; i++)
    {
        cout << ans[i] << ' ';
    }
}