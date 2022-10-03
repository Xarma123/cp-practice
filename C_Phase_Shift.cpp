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
        map<char, char> nx;
        set<char> used;
        string ans = "";
        for (lol i = 0; i < s.size(); i++)
        {
            if (nx.count(s[i]))
            {
                ans.push_back(nx[s[i]]);
            }
            else
            {
                for (char a = 'a'; a <= 'z'; a++)
                {
                    if (a != s[i] && !used.count(a))
                    {
                        nx[s[i]] = a;
                        char c = a;
                        lol co = 1;
                        while (nx.count(c) && c != s[i])
                        {
                            co++;
                            c = nx[c];
                        }
                        if ((c == s[i] && co == 26) || c != s[i])
                        {
                            used.insert(a);
                            i--;
                            break;
                        }
                        else
                        {
                            nx.erase(s[i]);
                        }
                    }
                }
            }
        }
        cout << ans << endl;
    }

    return 0;
}