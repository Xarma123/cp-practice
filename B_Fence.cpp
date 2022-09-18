#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, k;
    cin >> n >> k;
    lol a[n];
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    lol ans = 0;
    for (lol i = 0; i < k; i++)
    {
        ans += a[i];
    }
    lol ci = 0;
    lol cs = ans;
    for (lol i = k; i < n; i++)
    {
        cs += a[i];
        cs -= a[i - k];
        if (cs < ans)
        {
            ans = cs;
            ci = i - k + 1;
        }
    }
    cout << ci + 1;

    return 0;
}