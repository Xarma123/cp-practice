#include <bits/stdc++.h>
#define lol long long
using namespace std;
lol fact(lol n)
{
    lol s = 1;
    lol ans = 1;
    while (s <= n)
    {
        ans = (ans * 1ll * s) % (long long)(1e9 + 7);
        s++;
    }
    return ans;
}
int main()
{
    lol n, x, p;
    cin >> n >> x >> p;

    lol up = n - x;
    lol dw = x - 1;
    lol s = 0;
    lol e = n;
    lol ans = 1;
    lol space = n - 1;

    while (s < e)
    {
        lol m = (s + e) / 2;
        if (m == p)
        {
            s = m + 1;
        }
        else if (m > p)
        {
            e = m;

            ans = (ans * 1ll * up) % (long long)(1e9 + 7);
            up--;
            space--;
        }
        else
        {

            s = m + 1;

            ans = (ans * 1ll * dw) % (long long)(1e9 + 7);
            dw--;
            space--;
        }
    }

    if (s > 0 && (s - 1) == p)
    { 
        ans=(ans*1ll*fact(space))%(long long)(1e9+7);
    }
    else
    ans=0;
    cout<<ans;

    return 0;
}