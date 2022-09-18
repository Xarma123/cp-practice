#include<iostream>
using namespace std;
lol ways(lol n)
{
    if(n==0)
    return 0 ;
    if(n==1|n==2|n==3)
    return 1;
    if(n==4)
    return 2;
    return ( ways(n-1)+ways(n-4) ) ;
    
}
int main()
{
    lol  n ; 
    cin>>n;
    cout<<ways(n);
}