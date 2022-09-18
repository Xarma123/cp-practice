#include <bits/stdc++.h>
using namespace std; 
  lol compare(const void* ap, const void* bp)
{
  
    const lol* a = (lol*)ap;
    const lol* b = (lol*)bp;
  
    if (*a < *b)
        return -1;
    else if (*a > *b)
        return 1;
    else
        return 0;
}

int main()
{
  long long n;
  cin >> n;
  long long a[n];
  for (long long  i = 0; i < n; i++)
  {
    cin>>a[i];
  } long long n2;
   cin>>n2;
  for (long long i = 0; i < n2; i++)
  {    long long t ; cin>>t;
    long long * at= (long long *)bsearch(&t,a,n,sizeof(a[0]),compare);
     if(at)
     {
       cout<<(at-a)<<" ";
     }
     else
     cout<<-1<<" ";
  }
  
  return 0;
}