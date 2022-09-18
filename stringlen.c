#include <stdio.h>
  lol len(char *);
int main()
{    char a[100];
scanf(" %[^\n]s",a);
     lol l = len(a);
      prlolf(" %d",l);
 
    return 0;
}



lol len(char *a)
{    static lol count = 0;
           if(*(a)!='\0')
              { ++count; 
                      
                
                   len((a+1));
                  
              }   
              else 
              return count;
    
}