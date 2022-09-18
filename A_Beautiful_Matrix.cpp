#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    lol ans = 0;
    for (lol i = 0; i < 5; i++)
    {
        for (lol j = 0; j < 5; j++)
        {
            lol t;
            cin >> t;
            if (t)
            {
                ans += abs(i - 2) + abs(j - 2);
            }
        }
    }
    cout << ans;

    return 0;
}