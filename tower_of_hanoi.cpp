#include<iostream>
using namespace std;
void tower(lol n , char src , char hlp, char dest )
{   if(n==0)
     return ;
      tower(n-1,src,dest,hlp);
      cout<<"Move "<<n<<"th disc from "<<src<<" to "<<dest<<endl;
      tower(n-1,hlp,src,dest);
      
}

int main()
{   lol n ; cin>>n;
   tower(n,'a','b','c');

}