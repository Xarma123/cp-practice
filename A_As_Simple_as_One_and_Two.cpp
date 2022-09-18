#include <bits/stdc++.h>
#define lol long long
using namespace std;
pair<lol, set<lol>> sub(string a, string b)
{
    lol ans = 0;
    lol n = b.size();
    set<lol> x;
    for (lol i = 0; i <= a.size() - n; i++)
    {
        string t2 = a.substr(i, n);
        if (t2 == b)
        {
            ans++;
            x.insert(i);
        }
    }

    return make_pair(ans, x);
}
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;

        pair<lol, set<lol>> two = sub(s, "two");
        pair<lol, set<lol>> twone = sub(s, "twone");
        pair<lol, set<lol>> one = sub(s, "one");
        for (auto i = twone.second.begin(); i != twone.second.end(); i++)
        {
            if (one.second.find((*i) + 2) != one.second.end())
            {
                one.second.erase(one.second.find((*i) + 2));
            }
            if (two.second.find((*i)) != two.second.end())
            {
                two.second.erase(two.second.find((*i)));
            }
        }
        cout << two.first + one.first - twone.first << endl;
        for (auto i = twone.second.begin(); i != twone.second.end(); i++)
        {
            cout << (*i) + 3 << " ";
        }
        for (auto i = one.second.begin(); i != one.second.end(); i++)
        {
            cout << (*i) + 2 << " ";
        }
        for (auto i = two.second.begin(); i != two.second.end(); i++)
        {
            cout << (*i) + 2 << " ";
        }
        cout << endl;
    }

    return 0;
}