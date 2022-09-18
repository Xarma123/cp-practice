#include <iostream>
using namespace std; 


lol find(lol n ){
 
     lol s2=0; lol t = n;
     while (t>0)
     {     s2+=t/2;
             t=t/2;
         
     }   
      t=n; lol s5 =0 ;
        while (t>0)
     {     s5+=t/5;
             t=t/5;
         
     }  
      
       if(s2>=s5)
       return s5;
       else return s2;
         
    


}
int main()
{ 
    lol n ; cin>>n;
      cout<<find(n);
    
     
      
} 