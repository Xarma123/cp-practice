#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol n;
    cin >> n;
    string s;
    cin >> s;
    lol ans = 0;
    lol v = 0;
    lol p = 0;
    while (p < n)
    {
        while (s[p] == '1')
        {
            v++;
            p++;
            if (p == n)
                break;
        }
        ans = ans * 1ll * 10 + v;

        p++;

        v = 0;
    }
    if (s[n - 1] == '0')
        ans = ans * 1ll * 10;
    cout << ans;

    return 0;
}