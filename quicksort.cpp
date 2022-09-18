#include <iostream>
using namespace std;
lol partition(lol a[], lol lb, lol ub)
{     
    lol p = a[lb];
    lol s = lb;
    lol e = ub;
    while (s <= e)
    {  
        while (a[s] <= p)
        {
            s++;
        }
        while (a[e] > p)
        {    if(e==0) break;
            e--;
        }
        if (s < e)
        {
            swap(a[s], a[e]);
        } 
    
    } 
    swap(a[lb], a[e]);  
    return e; 
}
void quick(lol a[], lol s , lol e)
{
       
         if (s<e)
         {
             
         
         
    
    lol m = partition(a,s,e);
    quick(a,s,m-1);
    quick(a,m+1,e); }
    
  return;
    
}
int main()
{
    lol n;
    cin >> n;
    lol a[n];
    for (lol i = 0; i < n; i++)
    {
        cin>>a[i];
    } 
    
    quick(a, 0, n-1);

    for (lol i = 0; i < n; i++)
    {
        cout<<a[i]<<" ";
    }
    
}