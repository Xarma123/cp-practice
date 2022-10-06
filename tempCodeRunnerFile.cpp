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
    lol ans = 0;
    lol c = 0;
    while (n > 1)
    {
        ans++;
        if (n % 2 == 0)
        {
            if ((n / 2) % 2 == 0)
                n /= 2;
            else
                n = (n - 2) / 2 + 2;
        }
        else
        {
            n--;
        }
    }
    cout << ans;

    return 0;
}