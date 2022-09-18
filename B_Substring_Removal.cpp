#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol n;
    cin >> n;
    string s;
    cin >> s;
    lol st = 0;

    while (s[st] == s[0])
    {
        st++;
        if (st == n)
            break;
    }
    lol e = n - 1;
    while (s[e] == s[0])
    {
        e--;
        if (e < 0)
            break;
    }
    if (st == n)
    {
        cout << (((n)*1ll * (n + 1))  / 2)% (998244353);
    }
    else
    {
        lol ans = (n - e) * 1ll * (st+1) % (998244353);
        if (e == n - 1)
        {
            while (s[e] == s[n - 1])
            {
                e--;
            } 
            ans=(ans+n-1-e)% (998244353);
        } 
        cout<<ans;
    }

    return 0;
}