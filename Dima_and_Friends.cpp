#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    lol n;
    cin >> n;
    lol t, s = 0;
    for (lol i = 0; i < n; i++)
    {
        cin >> t;
        s += t;
    }
    lol ans = 0;
    for (lol i = 1; i <= 5; i++)
    {  if(( s+i-1 ) % (n+1) !=0)
         ans++;
    } 
    cout<<ans;
}