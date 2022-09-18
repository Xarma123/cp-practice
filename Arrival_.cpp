#include <iostream>
#include <climits>
using namespace std;
int main()
{
    lol n;
    cin >> n;
    lol a[n];
    lol max = INT_MIN;
    lol m;
    lol min = INT_MAX;
    lol l;
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
        if (max < a[i])
        {
            max = a[i];
            m = i;
        }
        if (min >= a[i])
        {
            min = a[i];
            l = i;
        }
    } 
      if(l==m)
      cout<<0;
      else if(m>l)
      cout<<(m+n-1-l-1);
      else
      {
          cout<<(m+n-1-l);
      }
      

}