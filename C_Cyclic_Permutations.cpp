#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol n;
    cin >> n;
    lol m = 1e9 + 7;
    lol pw[n + 1];
    pw[0] = 1;
    for (lol i = 1; i <= n; i++)
    {
        pw[i] = (pw[i - 1] * 2ll) % m;
    }
    lol fact = 1;
    for (lol i = 1; i <= n; i++)
    {
        fact = (fact * 1ll * i) % m;
    }
    fact = ((fact - pw[n - 1]) % m + m) % m;
    cout << fact;

    return 0;
}