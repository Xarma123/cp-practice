#include<iostream>
#include<conio.h>
using namespace std;
int main(){

  lol a;
  cin>>a;
  lol r=1;
  while (r<=a)
  {     lol c=1; 
         cout.width(50-r);
         cout<<r;
         lol b=r;
     while(c<=r-1){  
              b++;
              cout<<b;

         c++;  }
         for (lol i = 0; i < r-2; i++)
         {   b--;
             cout<<b;
         }
         if(r!=1){cout<<r;}
cout<<endl;
     r++;
  }
  


  getch();
  return 0;




}