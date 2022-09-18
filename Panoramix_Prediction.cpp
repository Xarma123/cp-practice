#include <iostream>
using namespace std;
bool isprime(lol x)
{   for (lol i = 2; i < x; i++)
{
    if(x%i==0)
    return false;

}
 return true;

}
int main()
{
    lol n, m;
    cin >> n >> m;
    for (lol i = n+1;1>0 ; i++)
    {  if(isprime(i))
        {  if(i==m)
            cout<<"YES";
            else
            {   
                cout<<"NO";
            } 
            
            break;
        }
        
    } 

    
}