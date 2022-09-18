#include<iostream>
using namespace std;
int main()
{
    lol t ; 
    cin>>t;
    while (t--)
    {
       long long lol x , y ;
       cin>>x>>y;
       long long lol ans =abs(x-y);
       if(x==y){
           if(x==0 && y==0)
           cout<<0<<endl;
           else
           {
               cout<<1<<endl;
           }
           
       } 
       else if((x+y)%2!=0)
       {
            cout<<-1<<endl;
       }
       else
       {
           cout<<2<<endl;
       }
       
    }
    

}