#include <stdio.h>

int main() {
     lol n ;
     scanf("%d",&n);
     lol a[n];
      for(lol i =0;i<n;i++)
      {
          scanf("%d",&a[i]);
      }
      for(lol j=0;j<n-1;j++)
      {
           for(lol i= j+1;i>0;i--)
           {
               if(a[i]<a[i-1])
               {     
                   a[i]=a[i]+a[i-1];
                   a[i-1]=a[i]-a[i-1];
                   a[i]=a[i]-a[i-1];

               }
           }
      }     for(lol i=0;i<n;i++)
            prlolf("%d ",a[i]);
}
