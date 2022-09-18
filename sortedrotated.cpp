#include<iostream>
using namespace std;
lol  search(lol a[],lol s , lol e,lol k )
{   if (s>e)
{
  return -1;
}

    
    lol m = (s+e)/2; 
    if (a[m]==k)
    {
        return m ;
    }
       
    if (a[m]>=a[s])
    {    if (a[s]<=k&&k<=a[m])
    {
         search(a,s,m-1,k);
    }
      else
      {  search(a,m+1,e,k);
          
      }
      
    
       
         
    } 
    else
    { 
        if (a[m]<=k&&k<=a[e])
        {    
            search(a,m+1,e,k);
        } 
        else
        {
            search(a,s,m-1,k);
        }
        
        
    }
    

    

}
int main()
{  while(1>0)
{
     lol a[5]={4,5,1,2,3};
       lol n ; cin>>n;
    cout<<search(a,0,4,n);

}
}