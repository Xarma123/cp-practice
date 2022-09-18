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
    lol a[n];
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    lol ans = LONG_LONG_MIN;
    for (lol i = 0; i < n; i++)
    {
        lol c = 1;
        for (lol j = i + 1; j < n; j++)
        {
            if (a[j] > a[j - 1])
            {
                break;
            }
            c++;
        }

        for (lol j = i - 1; j >= 0; j--)
        {
            if (a[j] > a[j + 1])
            {
                break;
            }
            c++;
        }
        ans = max(ans, c);
    }
    cout << ans;

    return 0;
}