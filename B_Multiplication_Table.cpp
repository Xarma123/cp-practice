#include <bits/stdc++.h>
#define lol long long
using namespace std;
lol n, k;
bool check(lol x)
{
  
    lol ans = 0;
    if (x > n * n)
        return false;
    for (lol i = 1; i <= n; i++)
    {
        if (x % i)
        {
            ans += min(x / i, n);

        }
        else
        {
            ans += min(x / i - 1, n);
           
        }
    }
    return (ans <= k);
}
int main()
{

    cin >> n >> k;
    
    
    lol s = 1;
    lol e = n * n + 1;
    while (s != e - 1)
    {
        lol m = (s + e) / 2; lol t = INT_MIN;
        for (lol i = 1; i <= n; i++)
        {
            t = max(t,min((m/i)*i,n*n));
        }
        
        if (check(t))
            s = t;
        else
            e = t;
    }
    cout << s;
    return 0;
}