#include <stdio.h>
int main()
{   
   lol x[3][5]={
       {1,2,3,4,5},
       {6,7,8,9,10},
       {11,12,13,14,15}
   };  
   prlolf("%d", *(*(x+1)));



}