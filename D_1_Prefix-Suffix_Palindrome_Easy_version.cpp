#include <bits/stdc++.h>
#define lol long long
using namespace std;
bool is(string a)
{
    lol s = 0;
    lol e = a.size() - 1;
    while (s < e)
    {
        if (a[s] != a[e])
            return false;
        s++;
        e--;
    }
    return true;
}
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        lol st = 0;
        lol e = s.size() - 1;
        while (s[st] == s[e] && st < e)
        {
            st++;
            e--;
        }
        if (st == e)
            cout << s << endl;
        else
        {
            string ans = "";
            for (lol i = st; i <= e; i++)
            {
                if (is(s.substr(st, i - st + 1)))
                {   
                    if (ans.size() < s.substr(st, i - st+1).size())
                        ans = s.substr(st, i - st+1);
                }
                if (is(s.substr(i, e - i + 1)))
                {
                    if (ans.size() < s.substr(i, e - i + 1).size())
                        ans = s.substr(i, e - i + 1);
                }
            }
            ans = s.substr(0, st) + ans;
            if (e + 1 < s.size())
                ans = ans + s.substr(e + 1);
            cout<<ans<<endl;
        }
    }

    return 0;
}