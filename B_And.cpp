#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, x;
    cin >> n >> x;
    lol b[n];
    lol a[n];
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n);
 
    for (lol i = 0; i < n; i++)
    {
        b[i] = (a[i] & x);
    }

    for (lol i = 1; i < n; i++)
    {
        if (a[i] == a[i - 1])
        {
            cout << 0;
            return 0;
        }
    }

    for (lol i = 0; i < n; i++)
    {
        if (binary_search(a, a + i, b[i]) || (i < n - 1 && binary_search(a + i + 1, a + n, b[i])))
        {
            cout << 1;
            return 0;
        }
    }
    sort(b, b + n);
    for (lol i = 1; i < n; i++)
    {
        if (b[i] == b[i - 1])
        {
            cout << 2;
            return 0;
        }
    }
    cout << -1;
    return 0;
}