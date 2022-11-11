#include<bits/stdc++.h>
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
    lol sum = 0;
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    if (sum % 3 != 0)
        cout << 0;
    else
    {
        sum /= 3;
        lol cl[n];
        lol csum = 0;
        for (lol i = 0; i < n; i++)
        {
            cl[i] = 0;
            if (i)
                cl[i] += cl[i - 1];
            csum += a[i];
            if (csum == sum)
                cl[i]++;
        }

        csum = 0;
        lol ans = 0;
        for (lol i = n - 1; i > 1; i--)
        {
            csum += a[i];
            if (csum == sum)
            {
                ans += cl[i-2];
            }
        }
        cout << ans;
    }

    return 0;
}