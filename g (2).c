#include <stdio.h>

int main() {
     
     lol a[100];
      for(lol i =0;i<100;i++)
      {
          a[i]=i+1;
      }   
      for(lol i=2;i<100;i++)
      {    if(a[i]!=0)
            {
                for(lol j=i+1;j<100;j++)
                {     if(a[j]%a[i]==0)
                       a[j]=0;
                      
                }
            }
            
      }   
            for(lol i=1;i<100;i++) {
                   if(a[i]!=0) prlolf(" %d ",a[i]);
            }
}