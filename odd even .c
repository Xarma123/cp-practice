#include <stdio.h>

int main() {
     lol c ;
     scanf("%d",&c);
     lol a[c];
      for(lol i =0;i<c;i++)
      {
          scanf("%d",&a[i]);
      }    lol p =0, n=0 , e=0 , o =0;
          for(lol i=0;i<c;i++)
          {      if(a[i]!=0)
             { if(a[i]>0) p++; else n++;
               if(a[i]%2==0)e++; else o++;
             
             
             }

          }     prlolf( " %d  %d  %d  %d ",p,n,e,o); 
}
