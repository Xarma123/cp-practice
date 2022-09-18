// SOUMYA SHARMA
// Trying to Code :'(
#include <bits/stdc++.h>

using namespace std;
int main()
{
    long long lol q;
    cin >> q;
    while (q--)
    {
        long long lol n;
        cin>>n;
        long long lol both1=0, both0=0, team=0, upper1=0, lower1=0;
        string p, e;
        cin>>p>>e;lol k;
        
        for (long long lol i = 0; i < n; i++)
        {  
            if ((p.at(i)=='1') &&( p.at(i) == e.at(i)))
            {  
                both1++;
            }
            else if (p.at(i)=='0' && p.at(i) == e.at(i))
            {
                both0++;
            }
            else if (p.at(i)=='1')
            {
                upper1++;
            }
            else if (e.at(i)=='1')
            {
                lower1++;
            }
           
        }   
      

     


       if(upper1==lower1)
      { team+=upper1;
         upper1=0;
         lower1=0;
      }
       if (upper1>lower1)
       {
           team+=lower1;
           upper1=upper1-lower1;
           lower1=0;
       } 
       else
       {
           team+=upper1;
           lower1=lower1-upper1;
           upper1=0;
       } 
       if ((upper1+lower1+both0)>=both1)
       {
            team+=both1;
       }
       else
       {
           team+=(upper1+lower1+both0);
       }
       
       
      
        cout<<team<<endl; 
       

       

    }

    return 0;
}