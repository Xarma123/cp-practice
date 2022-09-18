#include <iostream>
#include <string.h>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{ 
    lol n ; cin>>n; lol ans=0;lol t;
    for (lol i = 0; i < n; i++)
    {  lol k=0;
        for (lol j = 0; j < 3; j++)
        { cin>>t;
        if(t==1)
        k++;
            
        } 
        if(k>=2)
        ans++;
        
    } 

    cout<<ans;
    

}