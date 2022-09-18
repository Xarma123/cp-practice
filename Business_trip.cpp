#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    lol k;
    cin >> k;
    lol a[12];
    for (lol i = 0; i < 12; i++)
    {
        cin >> a[i];
    } 
    sort(a,a+12);lol i;
    lol sum=0;lol ans=0;
    for ( i = 11; i>=0; i--)
    { if (sum>=k)
        {   break;
            
        }
        sum+=a[i]; ans++;
        if (sum>=k)
        {   break;
            
        }
         
    } 
    if(i==-1)
    { 
        cout<<-1;

    }
    else
    {
        cout<<ans;
    }
    
    
}