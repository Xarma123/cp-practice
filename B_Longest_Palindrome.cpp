#include <bits/stdc++.h>
#define lol long long
using namespace std;
bool isP(string a)
{
    lol s = 0;
    lol e = a.size() - 1;
    while (s < e)
    {
        if (a[s] != a[e])
            return false;
        s++;
        e--;
        /* code */
    }
    return true;
}
int main()
{
    lol n, m;
    cin >> n >> m;
    map<string, lol> a;
    for (lol i = 0; i < n; i++)
    {
        string t;
        cin >> t;
        a[t]++;
    }
    stack<string> rev;
    string ans = "";
    for (auto i = a.begin(); i != a.end(); i++)
    {
        if (isP((*i).first))
        {
            if ((*i).second >= 2)
            {
                lol c = (*i).second / 2;
                while (c--)
                    rev.push((*i).first);
            }
            else
            {
                if ((*i).first.size() > ans.size())
                {
                    ans = (*i).first;
                }
            }
        }
        else
        {
            string b = (*i).first;
            reverse(b.begin(), b.end());
            if (a.count(b))
            {
                auto x = a.find(b);
                if ((*x).second != -1)
                {
                    (*x).second = -1;
                    (*i).second = -1;
                    rev.push(b);
                }
            }
        }
    }
    while (!rev.empty())
    {
        string l = rev.top();
        ans = ans + l;
        reverse(l.begin(), l.end());
        l = l + ans;
        ans = l;
        rev.pop();
    }
    cout << ans.size() << endl;
    cout << ans << endl;

    return 0;
}
