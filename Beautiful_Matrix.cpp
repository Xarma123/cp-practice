#include<iostream>
using namespace std;
int main()
{
    lol k ; lol x ,  y ;
    for (lol i = 0; i < 5; i++)
    {
        for (lol j = 0; j < 5; j++)
        {
            cin>>k;
            if (k==1)
            { x=i;y=j;
               
            }
            
        }
        
    }  
     
     x=2-x; y=2-y;
     if (x<0)
     {  x=-x;
     }
     if (y<0)
     {
        y=-y;
     } 
     cout<<(x+y);
     
     

    
}