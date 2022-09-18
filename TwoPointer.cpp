#include <iostream>
#include <conio.h>
#include<algorithm>
using namespace std;
bool compare(lol a , lol b){  return a<b;}
int main()
{lol n ; cin>>n; lol a[n]; 
   for (lol i = 0; i < n; i++)
   {
       cin>>a[i];
   }
   
sort(a,a+n,compare);
     lol s=0,e=n-1;
      lol v;cin>>v;lol z=0;
      lol q=a[s]+a[e]; 
           while (s<e)
           {     q=a[s]+a[e]; 
                 if (q>v)
           {
               e--;
           }if (q<v)
           {
              s++;
           }if (q==v)
           {
              cout<<a[s]<<" "<<a[e]<<endl;
              s++; z++;
           }
           
           
           
              
           }      if (z==0)
           {
             cout<<" no such pair";
           }
           
             

      getch();
      return 0;
}