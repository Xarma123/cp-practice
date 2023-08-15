#include <bits/stdc++.h>
using namespace std;
#define lol long long
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
    lol l[n], r[n];
    l[0] = ~a[0];
    r[n - 1] = ~a[n - 1];
    for (lol i = 1; i < n; i++)
    {
        l[i] = (~a[i]) & l[i - 1];
    }
    for (lol i = n - 2; i >= 0; i--)
    {
        r[i] = (~a[i]) & r[i + 1];
    }
    lol ans = LONG_LONG_MIN;
    lol id = 0;
    for (lol i = 0; i < n; i++)
    {
        lol c = a[i];
        if (i - 1 >= 0)
            c &= l[i - 1];
        if (i + 1 < n)
            c &= r[i + 1];
        if (ans < c)
        {
            id = i;
            ans = c;
        }
    }
    swap(a[0], a[id]);
    for (lol i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}