#include <bits/stdc++.h>
using namespace std;
#define lol long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol t;
    cin >> t;
    while (t--)
    {
        lol a, b, n, m;
        cin >> a >> b >> n >> m;
        map<lol, deque<lol>> xmp, ymp;
        for (lol i = 0; i < n; i++)
        {
            lol x, y;
            cin >> x >> y;
            xmp[x].push_back(y);
            ymp[y].push_back(x);
        }

        for (auto e : xmp)
        {
            sort(e.second.begin(), e.second.end());
            xmp[e.first] = e.second;
        }
        for (auto e : ymp)
        {
            sort(e.second.begin(), e.second.end());
            ymp[e.first] = e.second;
        }
        lol mnr = 1, mxr = a;
        lol mnc = 1, mxc = b;
        lol var = 0;
        lol alice = 0, bob = 0;
        while (m--)
        {
            var++;
            char c;
            cin >> c;
            lol k;
            cin >> k;
            if (c == 'U')
            {
                lol r = mnr + k - 1;
                set<lol> ys;
                lol score = 0;
                vector<lol> er;
                for (auto i = xmp.begin(); i != xmp.end(); i++)
                {
                    if (i->first <= r)
                    {
                        er.push_back((i->first));
                        for (auto e : i->second)
                        {
                            ys.insert(e);
                            score++;
                        }
                    }
                    else
                        break;
                }
                for (auto e : er)
                    xmp.erase(e);
                mnr += k;
                for (auto y : ys)
                {
                    while (ymp[y].size() > 0 && ymp[y].front() <= r)
                    {
                        ymp[y].pop_front();
                    }
                }
                if (var % 2)
                {
                    alice += score;
                }
                else
                    bob += score;
            }
            else if (c == 'D')
            {
                lol r = mxr - k + 1;
                set<lol> ys;
                lol score = 0;
                vector<lol> er;
                for (auto i = xmp.rbegin(); i != xmp.rend(); i++)
                {
                    if (i->first >= r)
                    {
                        er.push_back((i->first));
                        for (auto e : i->second)
                        {
                            ys.insert(e);
                            score++;
                        }
                    }
                    else
                        break;
                }
                for (auto e : er)
                    xmp.erase(e);
                mxr -= k;
                for (auto y : ys)
                {
                    while (ymp[y].size() > 0 && ymp[y].back() >= r)
                    {
                        ymp[y].pop_back();
                    }
                }
                if (var % 2)
                {
                    alice += score;
                }
                else
                    bob += score;
            }
            else if (c == 'L')
            {
                lol c = mnc + k - 1;
                set<lol> xs;
                lol score = 0;
                vector<lol> er;
                for (auto i = ymp.begin(); i != ymp.end(); i++)
                {
                    if (i->first <= c)
                    {
                        er.push_back((i->first));
                        for (auto e : i->second)
                        {
                            xs.insert(e);
                            score++;
                        }
                    }
                    else
                        break;
                }
                for (auto e : er)
                {
                    ymp.erase(e);
                }
                mnc += k;
                for (auto x : xs)
                {
                    while (xmp[x].size() > 0 && xmp[x].front() <= c)
                    {
                        xmp[x].pop_front();
                    }
                }
                if (var % 2)
                {
                    alice += score;
                }
                else
                    bob += score;
            }
            else
            {
                lol c = mxc - k + 1;
                set<lol> xs;
                lol score = 0;
                vector<lol> er;
                for (auto i = ymp.rbegin(); i != ymp.rend(); i++)
                {
                    if (i->first >= c)
                    {
                        er.push_back((i->first));
                        for (auto e : i->second)
                        {
                            xs.insert(e);
                            score++;
                        }
                    }
                    else
                        break;
                }
                for (auto e : er)
                {
                    ymp.erase(e);
                }
                mxc -= k;
                for (auto x : xs)
                {
                    while (xmp[x].size() > 0 && xmp[x].back() >= c)
                    {
                        xmp[x].pop_back();
                    }
                }
                if (var % 2)
                {
                    alice += score;
                }
                else
                    bob += score;
            }
        }
        cout << alice << " " << bob << '\n';
    }

    return 0;
}
