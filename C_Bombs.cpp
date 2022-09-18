#include <bits/stdc++.h>
#define lol long long
using namespace std;
struct op
{
    lol type;
    lol dir;
    char c;
};
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n;
    cin >> n;
    lol ans = 0;
    vector<pair<lol, pair<lol, lol>>> p;
    vector<op> o;
    while (n--)
    {
        lol x, y;
        cin >> x >> y;
        p.push_back({abs(x) + abs(y), {x, y}});
    }
    sort(p.begin(), p.end());

    for (auto q : p)
    {
        lol y = q.second.first;
        lol x = q.second.second;
        if (x > 0)
        {
            o.push_back({1, abs(x), 'U'});
        }
        if (x < 0)
        {
            o.push_back({1, abs(x), 'D'});
        }
        if (y > 0)
        {
            o.push_back({1, abs(y), 'R'});
        }
        if (y < 0)
        {
            o.push_back({1, abs(y), 'L'});
        }
        o.push_back({2, 0, '\n'});
        if (x > 0)
        {
            o.push_back({1, abs(x), 'D'});
        }
        if (x < 0)
        {
            o.push_back({1, abs(x), 'U'});
        }
        if (y > 0)
        {
            o.push_back({1, abs(y), 'L'});
        }
        if (y < 0)
        {
            o.push_back({1, abs(y), 'R'});
        }
        o.push_back({3, 0, 'w'});
    }
    cout << o.size() << '\n';
    for (auto e : o)
    {
        if (e.type == 1)
        {
            cout << e.type << " " << e.dir << " " << e.c << '\n';
        }
        else
            cout << e.type << '\n';
    }

    return 0;
}