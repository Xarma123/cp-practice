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
    lol s = 0;
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
        s += a[i];
    }
    lol cs = 0;
    sort(a, a + n);
    lol i;
    for (i = n - 1; i >= 0; i--)
    {
        cs += a[i];
        if (cs > s - cs)
        {
            break;
        }
    }
    cout << n - i;

    return 0;
}