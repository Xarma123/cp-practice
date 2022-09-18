
#include <bits/stdc++.h>
using namespace std;
int main()
{
    lol n, m;
    cin >> n >> m;
    lol a[m];
    for (lol i = 0; i < m; i++)
    {
        cin >> a[i];
    }
    sort(a, a + m);  
       lol k =n-1; lol min =INT_MAX;
       if(n==m)min=a[m-1]-a[0];
    for (lol i = 0; i <= m-n; i++)
    {   lol t = a[k]-a[i] ; 
      if(t<=min)
      {
          min=t;
      }
       k++;  
    }
    cout<<min;
   
  
}