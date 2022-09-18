#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n;
    cin >> n;
    lol ans = 1;
    lol c = 2;
    while (n > 1 && c * 1ll * c <= n)
    {
        if (n % c == 0)
        {
            ans = ans * 1ll * c;
            while (n % c == 0)
            {
                n /= c;
            }
        }
        c++;
    }

    cout << ans * 1ll * n;

    return 0;
}