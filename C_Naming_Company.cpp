#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{

    string s;
    cin >> s;
    string t;
    cin >> t;
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    string ans = s;

    lol i1 = 0;
    lol j1 = t.size() - 1;
    lol i2 = 0;
    lol j2 = t.size() - 1;
    lol p = 0;
    lol q = t.size() - 1;
    while (p <= q)
    {
        if(s[i1]<=t[j1])
        {
            
            ans[p]=s[i1];
            p++;
            i1++;
        }
        else
        {
            ans[q]=s[j1];
        }
    }

    return 0;
}