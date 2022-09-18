#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol n;
        cin >> n;
        lol ans = 0;
        a:
        if ((n % 10) == 5 || (n % 10) == 0)
        {
             if(n%10==5)
             {
                 n=n/10;
                  b:
                 if(n%10==2||n%10==7) 
                 {
                     cout<<ans<<endl;
                 }
                 else
                 {
                     n=n/10;
                     ans++;
                     goto b;
                 }
             }
             else if(n%10==0)
             {
                 n=n/10; 
                 c:
                  if(n%10==0||n%10==5) 
                 {
                     cout<<ans<<endl;
                 }
                 else
                 {
                     n=n/10;
                     ans++;
                     goto c;
                 } 
             } 




        }
        else
        {
            n = n / 10;
            ans++;
            goto a;
        } 
       
         
    }

    return 0;
}