#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, m;
    cin >> n >> m;
    if (n >= m)
        cout << n - m;
    else
    {
        lol ans = 0;
        while (m > n)
        {
            if (m % 2 == 0)
                m /= 2;
            else
            {
                m = (m + 1) / 2;
                ans++;
            }
            ans++;
        }
        cout << ans + n - m;
    }

    return 0;
}