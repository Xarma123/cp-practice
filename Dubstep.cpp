#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{ 
    string a;
    cin>>a; 
    for (lol i = 0; i < a.size(); i++)
    {
        if(a[i]=='W')
        {
            if(a[i+1]=='U')
            {
                if (a[i+2]=='B')
                {
                a.erase(i,3);
                if(i!=0)
                 a.insert(i," ");
                 else
                 i--;
                
                }  
                
                
            }
        } 
       
        
    } 
   
    
    while (a[a.size()-1]==' ')
    {
        a.erase(a.size()-1,1);
    }
    
     

    cout<<a;
    

}