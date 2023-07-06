#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol n;
        cin >> n;
        lol ans = 1;
        while (n > 1)
        {
            ans += n;
            n /= 2;
        }
        cout << ans << '\n';
    }
}