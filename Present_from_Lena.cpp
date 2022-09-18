#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
int main()
{ lol n ; cin>>n; n++;
 for (lol row = 0; row < n ; row++)
 {      cout.width(2*n-2*row-1);
       if(row!=0)
   cout<<0<<' ';
   else cout<<0;
     for (lol col = 0; col < row; col++)
     {   cout<<(col+1)<<" ";
          
     } 

      for (lol col = row-1; col>0; col--)
     {   cout<<(col)<<" ";
          
     } 

    if(row!=0)
    cout<<0; cout<<endl;
 }
 for (lol row = n-2; row >= 0 ; row--)
 {      cout.width(2*n-2*row-1);
    if(row!=0)
   cout<<0<<' ';
   else cout<<0;
     for (lol col = 0; col < row; col++)
     {   cout<<(col+1)<<" ";
          
     } 

      for (lol col = row-1; col>0; col--)
     {   cout<<(col)<<" ";
          
     } 

    if(row!=0)
    cout<<0; cout<<endl;
 }
 
 


}