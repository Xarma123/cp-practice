#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol n, d;
    cin >> n >> d;
    lol a[n];
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    lol ans = 0;
    for (lol i = 0; i < n - 1; i++)
    {
        if (a[i + 1] - a[i] == 2 * d)
            ans++;
        else if (a[i + 1] - a[i] > 2 * d)
            ans += 2;
    }
    ans += 2; 
    cout<<ans;

    return 0;
}