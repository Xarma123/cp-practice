#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol T;
    cin >> T;
    while (T--)
    {
        lol n, m;
        cin >> n >> m;
        string a[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        vector<vector<lol>> ans;
        for (lol i = 0; i < n; i += 2)
        {
            for (lol j = 0; j < m; j += 2)
            {
                stack<pair<lol, lol>> o;
                stack<pair<lol, lol>> z;
                if (a[i][j] == '1')
                    o.push(make_pair(i, j));
                else
                    z.push(make_pair(i, j));
                if (j + 1 < m)
                {
                    if (i + 1 < n)
                    {
                        if (a[i][j + 1] == '1')
                            o.push(make_pair(i, j + 1));
                        else
                            z.push(make_pair(i, j + 1));

                        if (a[i + 1][j + 1] == '1')
                            o.push(make_pair(i + 1, j + 1));
                        else
                            z.push(make_pair(i + 1, j + 1));

                        if (a[i + 1][j] == '1')
                            o.push(make_pair(i + 1, j));
                        else
                            z.push(make_pair(i + 1, j));
                    }
                    else
                    {
                        if (a[i][j + 1] == '1')
                            o.push(make_pair(i, j + 1));
                        else
                            z.push(make_pair(i, j + 1));

                        if (a[i - 1][j + 1] == '1')
                            o.push(make_pair(i - 1, j + 1));
                        else
                            z.push(make_pair(i - 1, j + 1));

                        if (a[i - 1][j] == '1')
                            o.push(make_pair(i - 1, j));
                        else
                            z.push(make_pair(i - 1, j));
                    }
                }
                else
                {
                    if (i + 1 < n)
                    {
                        if (a[i][j - 1] == '1')
                            o.push(make_pair(i, j - 1));
                        else
                            z.push(make_pair(i, j - 1));

                        if (a[i + 1][j - 1] == '1')
                            o.push(make_pair(i + 1, j - 1));
                        else
                            z.push(make_pair(i + 1, j - 1));

                        if (a[i + 1][j] == '1')
                            o.push(make_pair(i + 1, j));
                        else
                            z.push(make_pair(i + 1, j));
                    }
                    else
                    {
                        if (a[i][j - 1] == '1')
                            o.push(make_pair(i, j - 1));
                        else
                            z.push(make_pair(i, j - 1));

                        if (a[i - 1][j - 1] == '1')
                            o.push(make_pair(i - 1, j - 1));
                        else
                            z.push(make_pair(i - 1, j - 1));

                        if (a[i - 1][j] == '1')
                            o.push(make_pair(i - 1, j));
                        else
                            z.push(make_pair(i - 1, j));
                    }
                }

                if (o.size() == 3)
                {
                    vector<lol> p;
                    while (!o.empty())
                    {
                        p.push_back(o.top().first);
                        p.push_back(o.top().second);
                        a[o.top().first][o.top().second] = '0';
                        o.pop();
                    }
                    ans.push_back(p);
                }
                else if (o.size() == 2)
                {
                    vector<lol> p;
                    lol x1, y1;
                    x1 = o.top().first;
                    y1 = o.top().second;
                    o.pop();
                    a[o.top().first][o.top().second] = '0';
                    a[x1][y1] = '0';

                    p.push_back(x1);
                    p.push_back(y1);

                    lol c = 2;
                    while (c--)
                    {
                        p.push_back(z.top().first);
                        p.push_back(z.top().second);
                        o.push(make_pair(z.top().first, z.top().second));
                        z.pop();
                    }
                    z.push(make_pair(x1, y1));
                    ans.push_back(p);
                    p.clear();
                    while (!o.empty())
                    {
                        p.push_back(o.top().first);
                        p.push_back(o.top().second);

                        o.pop();
                    }
                    ans.push_back(p);
                }
                else if (o.size() == 1)
                {
                    vector<lol> p;
                    a[o.top().first][o.top().second] = '0';
                    lol X = o.top().first;
                    lol Y = o.top().second;
                    o.pop();
                    p.push_back(X);
                    p.push_back(Y);
                    lol c = 2;
                    while (c--)
                    {
                        p.push_back(z.top().first);
                        p.push_back(z.top().second);
                        o.push(make_pair(z.top().first, z.top().second));
                        z.pop();
                    }
                    z.push(make_pair(X, Y));
                    ans.push_back(p);
                    p.clear();
                    lol x1, y1;
                    x1 = o.top().first;
                    y1 = o.top().second;
                    o.pop();
                    a[o.top().first][o.top().second] = '0';
                    a[x1][y1] = '0';

                    p.push_back(x1);
                    p.push_back(y1);

                    c = 2;
                    while (c--)
                    {
                        p.push_back(z.top().first);
                        p.push_back(z.top().second);
                        o.push(make_pair(z.top().first, z.top().second));
                        z.pop();
                    }
                    z.push(make_pair(x1, y1));
                    ans.push_back(p);
                    p.clear();
                    while (!o.empty())
                    {
                        p.push_back(o.top().first);
                        p.push_back(o.top().second);

                        o.pop();
                    }
                    ans.push_back(p);
                }
                else if (o.size() == 4)
                {
                    vector<lol> p;
                    lol c = 3;
                    while (c--)
                    {
                        p.push_back(o.top().first);
                        p.push_back(o.top().second);
                        a[o.top().first][o.top().second] = '0';
                        z.push(make_pair(o.top().first, o.top().second));
                        o.pop();
                    }
                    ans.push_back(p);
                    p.clear();
                    a[o.top().first][o.top().second] = '0';
                    lol X = o.top().first;
                    lol Y = o.top().second;
                    o.pop();
                    p.push_back(X);
                    p.push_back(Y);
                    c = 2;
                    while (c--)
                    {
                        p.push_back(z.top().first);
                        p.push_back(z.top().second);
                        o.push(make_pair(z.top().first, z.top().second));
                        z.pop();
                    }
                    z.push(make_pair(X, Y));
                    ans.push_back(p);
                    p.clear();
                    lol x1, y1;
                    x1 = o.top().first;
                    y1 = o.top().second;
                    o.pop();
                    a[o.top().first][o.top().second] = '0';
                    a[x1][y1] = '0';

                    p.push_back(x1);
                    p.push_back(y1);

                    c = 2;
                    while (c--)
                    {
                        p.push_back(z.top().first);
                        p.push_back(z.top().second);
                        o.push(make_pair(z.top().first, z.top().second));
                        z.pop();
                    }
                    z.push(make_pair(x1, y1));
                    ans.push_back(p);
                    p.clear();
                    while (!o.empty())
                    {
                        p.push_back(o.top().first);
                        p.push_back(o.top().second);

                        o.pop();
                    }
                    ans.push_back(p);
                }
            }
        }
        cout << ans.size() << endl;
        for (lol i = 0; i < ans.size(); i++)
        {
            for (lol j = 0; j < ans[i].size(); j++)
            {
                cout << ans[i][j] + 1 << " ";
            }
            cout << endl;
        }
    }

    return 0;
}