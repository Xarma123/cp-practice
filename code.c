#include <iostream>
using namespace std;
int main() {
     lol n ;
     scanf("%d",&n);
     lol a[n];
      for(lol i =0;i<n;i++)
      {
          scanf("%d",&a[i]);
      }
      for(lol j=n-1;j>0;j--)
      {
           for(lol i=0;i<j;i++)
           {
               if(a[i]>a[i+1])
               {
                   a[i]=a[i]+a[i+1];
                   a[i+1]=a[i]-a[i+1];
                   a[i]=a[i]-a[i+1];

               }
           }
      }     for(lol i=0;i<n;i++)prlolf("%d ",a[i]);
}
