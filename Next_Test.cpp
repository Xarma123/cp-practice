#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol n;
    cin >> n;
    set<lol, greater<lol>> x;
    while (n--)
    {
        lol t;
        cin >> t;
        x.insert(t);
    } lol ans;
    for (auto i = x.begin(); i != x.end(); i++)
    {  
            if(x.find((*i)+1)==x.end())
            {
                ans= (*i)+1;
            } 

    }  
      if(*--x.end()>1)
      cout<<1;
      else    
    cout<<ans;


    return 0;
}