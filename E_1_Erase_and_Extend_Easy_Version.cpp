#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    lol i;
    string ans = "";
    for (i = 1; i < n; i++)
    {
        if (s[i] > s[0])
            break;
        else if (s[i] == s[0])
        {
            string c = s.substr(0, i);
            string q = "";
            for (lol j = 1; j <= k; j++)
            {
                if (j % (c.size()) == 0)
                    q.push_back(c[c.size() - 1]);
                else
                    q.push_back(c[j % (c.size()) - 1]);
            }
            if (ans == "")
                ans = q;
                if(ans>q)
            ans = min(ans, q);
        }
    }
    string c = s.substr(0, i);
    string q = "";
    for (lol j = 1; j <= k; j++)
    {
        if (j % (c.size()) == 0)
            q.push_back(c[c.size() - 1]);
        else
            q.push_back(c[j % (c.size()) - 1]);
    }
    if (ans == "")
        ans = q;
    ans = min(ans, q); 
    cout<<ans;


    return 0;
}