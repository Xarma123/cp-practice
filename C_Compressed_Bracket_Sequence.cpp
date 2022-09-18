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
    lol c[n];
    lol l = 0, r = 0;
    lol ans = 0;
    for (lol i = 0; i < n; i++)
    {
        cin >> c[i];
        if (i % 2 == 0)
            l += c[i];
        if (i % 2 != 0)
        {
            if (l >= c[i])
            {
                ans += c[i];
                l -= c[i];
            }
            else
            {
                ans += l;
                l = 0;
            }
        }
    }
    cout<<ans;

    return 0;
}