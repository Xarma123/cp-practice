#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s;
    cin >> s;
    s = "(" + s + ")";
    bool ans = true;
    stack<map<char, lol>> x;
    map<char, lol> mp;
    for (lol i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
        {

            map<char, lol> f;
            lol j = i + 1;
            while (j < s.size() && (s[j] != ')' && s[j] != '('))
            {
                mp[s[j]]++;
                f[s[j]]++;
                j++;
            }
            x.push(f);
            i = j - 1;
        }
        else if (s[i] == ')')
        {
            for (auto e : x.top())
            {
                mp[e.first] -= e.second;
            }
            x.pop();
            lol j = i + 1;
            while (j < s.size() && (s[j] != ')' && s[j] != '('))
            {
                mp[s[j]]++;
                x.top()[s[j]]++;
                j++;
            }
            i = j - 1;
        }

        for (auto e : mp)
        {
            ans &= (e.second <= 1);
        }
    }
    for (auto e : mp)
    {
        ans &= (e.second <= 1);
    }
    if (ans)
        cout << "Yes";
    else
        cout << "No";

    return 0;
}