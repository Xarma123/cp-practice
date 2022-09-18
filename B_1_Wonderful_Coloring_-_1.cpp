#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        lol a[26];
        memset(a, 0, sizeof(a));
        for (lol i = 0; i < s.size(); i++)
        {
            a[s[i] - 'a']++;
        }
        lol ans = 0;
        for (lol i = 0; i < 26; i++)
        {
            if (a[i] >= 2)
            {
                ans++;
                a[i] = 0;
            }
        }
        lol c = 0;
        for (lol i = 0; i < 26; i++)
        {
            if (a[i] >= 1)
            {
                c++;
            }
        } 
        ans+=c/2; 
        cout<<ans<<endl;
    }

    return 0;
}