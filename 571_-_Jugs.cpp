#include <bits/stdc++.h>
#define lol long long
using namespace std;
string print(pair<lol, lol> a, pair<lol, lol> b)
{
    if (a.first == b.first)
    {
        if (a.second < b.second)
        {
            return "fill B";
        }
        else
        {
            return "empty B";
        }
    }
    else if (a.second == b.second)
    {
        if (a.first < b.first)
        {
            return "fill A";
        }
        else
        {
            return "empty A";
        }
    }
    else if (a.first < b.first)
    {
        return "pour B A";
    }
    else
        return "pour A B";
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol ca, cb, n;
    while (cin >> ca >> cb >> n)
    {
        pair<lol, lol> st = {0, 0};
        map<pair<lol, lol>, pair<lol, lol>> parent;
        queue<pair<lol, lol>> q;
        q.push(st);
        set<pair<lol, lol>> used;
        used.insert(st);
        pair<lol, lol> f;
        while (!q.empty())
        {
            pair<lol, lol> top = q.front();
            lol f1 = top.first;
            lol f2 = top.second;
            q.pop();
            if (top.second == n)
            {
                f = top;
                break;
            }
            if (!used.count({0, f2}))
            {
                parent[{0, f2}] = top;
                q.push({0, f2});
                used.insert({0, f2});
            }
            if (!used.count({ca, f2}))
            {
                parent[{ca, f2}] = top;
                q.push({ca, f2});
                used.insert({ca, f2});
            }
            if (!used.count({f1, 0}))
            {
                parent[{f1, 0}] = top;
                q.push({f1, 0});
                used.insert({f1, 0});
            }
            if (!used.count({f1, cb}))
            {
                parent[{f1, cb}] = top;
                q.push({f1, cb});
                used.insert({f1, cb});
            }
            if (!used.count({max(f1 + f2 - cb, 0ll), min(f1 + f2, cb)}))
            {
                parent[{max(f1 + f2 - cb, 0ll), min(f1 + f2, cb)}] = top;
                q.push({max(f1 + f2 - cb, 0ll), min(f1 + f2, cb)});
                used.insert({max(f1 + f2 - cb, 0ll), min(f1 + f2, cb)});
            }
            if (!used.count({min(f1 + f2, ca), max(f1 + f2 - ca, 0ll)}))
            {
                parent[{min(f1 + f2, ca), max(f1 + f2 - ca, 0ll)}] = top;
                q.push({min(f1 + f2, ca), max(f1 + f2 - ca, 0ll)});
                used.insert({min(f1 + f2, ca), max(f1 + f2 - ca, 0ll)});
            }
        }
        stack<string> s;
        while (parent.count(f))
        {
            s.push(print(parent[f], f));
            f = parent[f];
        }
        while (!s.empty())
        {
            cout << s.top() << endl;
            s.pop();
        }
        cout << "success" << endl;
    }

    return 0;
}