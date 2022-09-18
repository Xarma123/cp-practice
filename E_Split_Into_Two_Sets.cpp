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
        vector<pair<lol, lol>> v;
        map<lol, vector<lol>> fre;
        bool f = false;
        for (lol i = 0; i < n; i++)
        {
            lol a, b;
            cin >> a >> b;
            v.push_back({a, b});
            if (a == b)
                f = true;
            fre[a].push_back(b);
            fre[b].push_back(a);
            if (fre[a].size() > 2 || fre[b].size() > 2)
                f = true;
        }
        if (f)
            cout << "NO" << endl;
        else
        {
            f = false;
            set<lol> x, y;
            for (lol i = 1; i <= n; i++)
            {
                if (fre[i].size() == 2)
                {
                    x.insert(i);
                    y.insert(i);
                    lol a = fre[i][0];
                    lol b = fre[i][1];

                    if (x.count(a) && y.count(a))
                        f = true;
                    else if (x.count(b) && y.count(b))
                        f = true;
                    else if (x.count(a) && y.count(b))
                    {
                        x.insert(b);
                        y.insert(a);
                    }
                    else if (x.count(b) && y.count(a))
                    {
                        x.insert(a);
                        y.insert(b);
                    }
                    else if (x.count(a))
                    {
                        x.insert(b);
                        y.insert(a);
                    }
                    else if (y.count(a))
                    {
                        x.insert(a);
                        y.insert(b);
                    }
                    else if (x.count(b))
                    {
                        x.insert(a);
                        y.insert(b);
                    }
                    else if (y.count(b))
                    {
                        x.insert(b);
                        y.insert(a);
                    }
                    else
                    {
                        x.insert(a);
                        y.insert(b);
                    }
                }
            }
            for (lol i = 1; i <= n; i++)
            {
                if (fre[i].size() == 1)
                {
                    
                }
            }

            if (f)
                cout << "NO" << endl;
            else
                cout << "YES" << endl;
        }
    }

    return 0;
}