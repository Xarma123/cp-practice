#include<bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol t; cin>>t;
    while (t--)
    {
        lol n,m;
        cin>>n>>m;
        string c;
        cin>>c;  lol h=0,v=0;
        for (lol i = 0; i < c.size(); i++)
        { 

            if(c[i]=='L')
               h--;
            else if(c[i]=='R')
               h++;
            else if(c[i]=='U')
               v--;
            else
             v++;
        }
         
         lol ax=0,ay=0;
         if(v<0)
         ay-=v;
         if(h<0)
         ax-=h;
         cout<<ay+1<<" "<<ax+1<<endl;
        
    }
    

return 0;
}