#include <iostream>
using namespace std;
int main()
{
   lol n ; cin>>n; string a;lol x=0;
   for (lol i = 0; i < n; i++)
   {  
       cin>>a;
       if(a[1]=='+')
       x++;
       else
       {
           x--;
       }
       

   } 
   cout<<x;
   

}