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
        lol a[n];
        lol ans = 0;
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
            ans += abs(a[i]);
        }
        lol c = 0;
        for (lol i = 0; i < n; i++)
        {
            if (a[i] < 0)
            {
                lol j = i + 1;
                while (j < n && a[j] <= 0)
                    j++;
                c++;
                i = j - 1;
            }
        }
        cout << ans << " " << c << '\n';
    }
}