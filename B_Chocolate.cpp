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
    lol i = 0;
    while (i < n && a[i] != 1)
        i++;
    if (i == n)
        cout << 0;
    else
    {
        lol ans = 1;
        for (lol j = i + 1; j < n; j++)
        {
            if (a[j])
            {
                ans *= j - i;
                i = j;
            }
        }
        cout << ans;
    }

    return 0;
}