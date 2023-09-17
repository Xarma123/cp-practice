#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, q;
    cin >> n >> q;
    lol a[n];
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
        if (i)
            a[i] += a[i - 1];
    }
    while (q--)
    {
        lol l, r;
        cin >> l >> r;
        r--;
        l--;
        l--;
        if (l >= 0)
            cout << a[r] - a[l] << '\n';
        else
            cout << a[r] << '\n';
    }
}