#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol n;
    cin >> n;
    lol a[n];
    lol s = LONG_LONG_MIN;
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
        s = max(a[i], s);
    }
    lol ans = 1;
    for (lol i = 0; i < n; i++)
    {
        if (a[i] == s)
        {
            lol j = i + 1;
            if (j < n)
            {
                while (a[j] == a[i])
                {
                    j++;
                    if (j == n)
                        break;
                }
            }

            ans = max(ans, (j - i));
            i = j;
        }
    }
    cout << ans;

    return 0;
}