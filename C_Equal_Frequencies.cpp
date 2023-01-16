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
        string s;
        cin >> s;
        map<char, lol> mp;
        for (auto e : s)
            mp[e]++;
        lol ans = LONG_LONG_MAX;
        lol d;
        for (lol i = 1; i < 27; i++)
        {
            if (n % i)
                continue;
            lol c = n / i;
            if (mp.size() <= i)
            {
                lol g = 0;
                for (auto e : mp)
                {
                    if (e.second > c)
                        g += e.second - c;
                }
                if (ans > g)
                {
                    ans = g;
                    d = i;
                }
            }
            else
            {
                vector<lol> q;
                for (auto e : mp)
                {
                    q.push_back(e.second);
                }
                sort(q.begin(), q.end());
                lol ex = mp.size() - i;
                lol g = 0;
                for (lol i = 0; i < q.size(); i++)
                {
                    if (ex)
                    {
                        g += q[i];
                        ex--;
                    }
                    else if (q[i] > c)
                    {
                        g += q[i] - c;
                    }
                }
                if (ans > g)
                {
                    ans = g;
                    d = i;
                }
            }
        }

        lol c = n / d;
        vector<lol> give;
        if (mp.size() > d)
        {
            vector<pair<lol, char>> q;
            for (auto e : mp)
            {
                q.push_back({e.second, e.first});
            }
            sort(q.begin(), q.end());
            lol ex = mp.size() - d;
            lol i = 0;
            while (ex--)
            {
                mp[q[i].second] = -1;
                i++;
            }
        }
        set<char> u;
        for (lol i = 0; i < n; i++)
        {
            if (mp[s[i]] != -1)
            {
                u.insert(s[i]);
            }
            else
                give.push_back(i);
            if (mp[s[i]] > c)
            {
                give.push_back(i);
                mp[s[i]]--;
            }
        }
        cout << give.size() << endl;
        for (auto e : mp)
        {
            while (c - e.second > 0 && e.second > 0)
            {

                e.second++;
                s[give.back()] = e.first;
                give.pop_back();
            }
        }
        if (mp.size() < d)
        {
            lol ex = d - mp.size();
            while (ex--)
            {
                lol cc = c;
                char put = 'a';
                while (u.count(put))
                    put++;
                while (cc--)
                {
                    s[give.back()] = put;
                    give.pop_back();
                }
                u.insert(put);
            }
        }

        cout << s << endl;
    }

    return 0;
}