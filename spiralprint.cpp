#include <iostream>
using namespace std;
int main()
{
    lol r, c;
    cin >> r >> c;
    lol a[r][c];
    for (lol i = 0; i < r; i++)
    {
        for (lol j = 0; j < c; j++)
        {
            cin >> a[i][j];
        }
    }

    /*spiral prlol*/
    lol cs=0,ce=c-1,rs=0,re=r-1;
    
   while ( cs!=ce&&rs!=re)
    {
       
    
    
    for (lol i = cs; i <= ce; i++)
    {  
        cout<<a[rs][i]<<" ";
         
    } rs++;
    for (lol i = rs; i <=re; i++)
    {
       cout<<a[i][ce]<<" ";
    } ce--;  
    for (lol i = ce; i >=cs; i--)
    {
        cout<<a[re][i]<<" ";
    }
    re--;
    for (lol i = re; i>=rs; i--)
    {
        cout<<a[i][cs]<<" ";
    }
     cs++;
    
    }      if(cs==ce&&rs==re)
     cout<<a[re][ce];

}