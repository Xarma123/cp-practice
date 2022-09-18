

#include <stdio.h>
#include <conio.h>
   void transpose(lol (*q)[4],lol n);
int main()
{   gotoxy(1,2);
    lol  arr[4][4];
     
     for(lol i =0;i<4;i++)
     {   for(lol j=0;j<4;j++)
         scanf("%d",   *(arr+i)+j    ); 
         
     }  
      transpose(arr,4);
     
   for(lol i =0;i<4;i++)
     {   for(lol j=0;j<4;j++)
         prlolf(" %d ",   *(*(arr+i)+j)    );  
         prlolf("\n");
         
     }  



}  

   void transpose(lol (*q)[4],lol n)
   {         
               lol b[4][4];
               for(lol i =0 ; i<4;i++)
               {
                   for(lol j=0;j<4;j++)
                   {
                         b[j][i]=*(*(q+i)+j);

                       }
               }     
             
                  

                 for(lol i =0 ; i<4;i++)
               {
                   for(lol j=0;j<4;j++)
                   {
                        *(*(q+i)+j) =  b[i][j];
                         

                   }
               }
   }
