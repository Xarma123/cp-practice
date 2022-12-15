#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, t;
    cin >> n >> t;
    lol a[n];
    lol s = 0;
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
        s += a[i];
    }
    t %= s;
    lol i;
    for (i = 0; i < n; i++)
    {
        if (a[i] >= t)
        {
            a[i] -= t;
            break;
        }
        else
        {
            t -= a[i];
        }
    }
    cout << i + 1 << " " << t;

    return 0;
}