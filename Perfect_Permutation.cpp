#include<iostream>
using namespace std;
int main()
{ 
    lol n;
    cin>>n;
    if (n&1!=0)
    {
        cout<<-1;
    }
    else
    {
        for (lol i = 1; i <=n; i++)
        {
            if(i&1==1)
            { cout<<i+1<<" ";

            }
            else
            {
                cout<<i-1<<" ";
            }
            
        }
        
    }
    
    


}