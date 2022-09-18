#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol n;
    cin >> n;
    lol a[n];
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n);
    lol ans = 0;
    for (lol i = 0; i < n; i++)
    {
        lol s = 0;
        s += a[i] + n;
        lol t = n - 1;
        lol j;
        for (j = 0; j < n; j++)
        {
            if (j != i)
            {
                if (a[j] + t > s)
                {
                    break;
                }
                t--;
            }
        }
        if (j == n)
            ans++;
    }
    cout << ans;

    return 0;
}