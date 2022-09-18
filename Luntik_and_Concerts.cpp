#include<bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{ 
    lol t; cin>>t;
    while (t--)
    {  
        lol a,b,c;
        cin>>a>>b>>c;
        lol sum = a+ 2*b +3*c;
        if(sum%2==0)
        {
            cout<<0<<endl;
        }
        else
        {
            cout<<1<<endl;
        }
     


        

     
    }
    

return 0;
}