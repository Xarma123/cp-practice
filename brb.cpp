#include <iostream>
#include <algorithm>
using namespace std;
int main()
{   long long lol t; cin>>t;
  while (t--)
  {
      
  
  
   long long  lol n;
    cin >> n;
   long long  lol a[n];
   
    for (long long lol i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    lol k = 1;
    for (long long lol i = 0; i < n; i++)
    {
        if (i != n - 1)
        {

            if ((a[i] == 0 && a[i + 1] == 1)&&(k==1))
            {
                cout << (i + 1) << " " << n + 1<<" ";
                k=0;
            } 
            else
            {
                 cout <<( i + 1)<<" ";
            }
            
        }
          else
        {
              cout <<( i + 1)<<" ";
        }
        
       
    }  
    
    if(k)
    cout << n + 1;
}}