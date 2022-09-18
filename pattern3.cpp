#include<iostream>
#include<conio.h>
using namespace std;
int main(){

     lol a ,c,r=1;
     cin>>a;
     while (r<=a)
     { 
          c=1;
          while (c<=r+1)
          {
                  if(r%2==0){
                       if (c%2==0)
                       {
                            cout<<1;
                       }else
                       {
                            cout<<0;
                       }
                       
                       
                  }
                  else
                  {  if (c%2==0)
                       {
                            cout<<0;
                       }else
                       {
                            cout<<1;
                       }
                       
                  }
        c++;          
          }
          r++;
          cout<<endl;       
     }
     









 getch();
 return 0;





}