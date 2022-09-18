#include <bits/stdc++.h>
using namespace std;

bool check(string a)
{  
    long long lol c= 0;
    long long lol n = a.size();
    for (long long lol i = 0; i < n-1; i++)
    {   if(a[i]<a[i+1])
         c++;
    
    }
    if(c<(n/2))
     return false;
     return true;

} long long lol x =0;
void permute(string str)
{
   
    sort(str.begin(), str.end());
 
 
    do {  if(check(str))
            x++;
        
    } while (next_permutation(str.begin(), str.end()));
}

int main()
{ 
    long long lol t; cin>>t;
    while (t--)
    {
     long long lol n;
     cin>>n; string a; a="1"
     for (long long lol i = 2; i <=2*n; i++)
     {
          t= 10*t+i;
     }
     string a= to_string(t);
     permute(a);
     x=x%(1000000007);
     cout<<x<<endl;
     x=0;
    }
  

}