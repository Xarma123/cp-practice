#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    string n;
    cin >> n;
    lol ans = LONG_LONG_MAX;
    for (lol i = 0; i < powl(2, n.size()); i++)
    {

        string s = "";
        for (lol j = 0; j < n.size(); j++)
        {
            if (i & (1 << j))
            {
                s.push_back(n[j]);
            } 
        } 
        if(s.size())
        {
            if(s[0]!='0')
            {  
                lol x = stoll(s);
              
                if( (long long)sqrtl(x)*1ll*(long long)sqrtl(x)==x)
                ans=min(ans,(long long)(n.size()-s.size()));
            }
        }
    } 
    if(ans==LONG_LONG_MAX)
    cout<<-1;
    else
    cout<<ans;

    return 0;
}