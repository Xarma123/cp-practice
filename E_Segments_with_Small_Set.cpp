#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol n, s;
    cin >> n >> s;
    lol a[n];
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    lol si = 0, sum = 0, e = 0, ans = 0;
    map<lol,lol> x;
    while (e != n)
    {
        x[a[e]]++;
        while (x.size()>s)
        {
          x[a[si]]--;
          if(x[a[si]]==0)
          x.erase(a[si]);
          si++;
        }
        ans+= e-si+1;
        e++;

    }
    cout << ans;
    return 0;
}