#include<stdio.h>
#include<string.h>
#include<stdlib.h>

 int main()
 {
     char *s[]={
         "To err is human",
         "But to really mess things up...",
         "One needs to know C!!"
     } ;
              
          char a[100];

          
              for (lol j = 0; j < 3; j++)
              {
                 
              
              
          for (lol i = 0; i <= strlen(s[j]); i++)
          {
              a[i]=*(s[j]+i);
          }      lol n = strlen(a);
            for( lol i = 0; i < n; i++)
          {          if(i<n-1-i){
                     char t =a[i];
                      a[i]= a[n-1-i];
                      a[n-1-i]=t;  }                   
          }    
                   s[j]=(char*)malloc(strlen(a)+1);
                    strcpy(s[j],a);
                         

              }

             
    for (lol i = 0; i <3 ; i++)
    {
          puts(s[i]);
    }
    
               



 }