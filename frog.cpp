#include <iostream>
#include <string>

using namespace std;
lol test(string b,long long lol d)
{
   long long lol n = b.size();
   long long lol i = 0;
    while (1 > 0)

    {  
        if ((i + d) >= n)
        {
            return 1;
        }
        else if (b[i] == 'R')
        {
           long long lol j;
           long long lol k = i;
            for (j = i + d; j > i; j--)
            {
                if (b[j] == 'R')
                {
                    i = j;
                    break;
                }
            }
            if (j == k)
            {
                return 0;
            }
        }
        else
        {
            i--;
        }
    }
}

int main()
{   lol t ; 
cin>>t;
for (lol q = 0; q < t; q++)
{
    



    string b;
    cin >> b;
    b.insert(0, 1, 'R');
 
  long long  lol s = 0 , e = b.size();
  long long  lol m;     
  long long lol ans;
    while (s<=e)
    {  
        m=(s+e)/2;
        if (test(b,m))
        {
            e=m-1;
            ans=m;
        }  
        else
        {
            s=m+1;
        }
       
      
                
    } 
    cout<<ans<<endl;
   
  

}

}