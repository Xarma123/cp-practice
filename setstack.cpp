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
        stack<set<lol>> s;
        lol c = 0;
        map<string, lol> mp1;
        map<lol, string> mp2;
        while (n--)
        {
            string o;
            cin >> o;
            if (o == "PUSH")
            {
                set<lol> q;
                s.push(q);
            }
            else if (o == "DUP")
            {
                s.push(s.top());
            }
            else if (o == "UNION")
            {
                set<lol> s1 = s.top();
                s.pop();
                set<lol> s2 = s.top();
                s.pop();
                set<lol> s3;
                set_union(s1.begin(), s1.end(), s2.begin(), s2.end(), inserter(s3, s3.begin()));
                s.push(s3);
            }
            else if (o == "INTERSECT")
            {
                set<lol> s1 = s.top();
                s.pop();
                set<lol> s2 = s.top();
                s.pop();
                set<lol> s3;
                set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(), inserter(s3, s3.begin()));
                s.push(s3);
            }
            else
            {
                set<lol> q = s.top();
                s.pop();
                string qq = "{";
                for (auto e : q)
                    qq = qq + to_string(e);
                qq = qq + "}";
                if (!mp1.count(qq))
                {
                    mp1[qq] = c++;
                    mp2[c - 1] = qq;
                }
                s.top().insert(mp1[qq]);
            }
            cout << s.top().size() << '\n';
        }
        cout << "***" << '\n';
    }

    return 0;
}