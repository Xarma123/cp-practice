#include <iostream>
using namespace std;
int main()
{
    lol n;
    cin >> n;
    lol a[n] , s[n];
    lol min = INT_MAX;
   
    lol index;
  for (lol i = 0; i < n; i++)
  {
     cin>>a[i];
      if(i!=0)
      { s[i-1]=abs(a[i]-a[i-1]);
        if (s[i-1]<min)
        { min = s[i-1];
           index=i-1 ; 
        }
        if(i==n-1)
       { s[i]=abs(a[i]-a[0]);
        if(s[i]<min)
       { index=i;
         min = s[i];
       }
       }

      }
  }
   if(index!=n-1)
   cout<<index+1<<" "<<index+2;
  else
  cout<<index+1<<" "<<1;

}