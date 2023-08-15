#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol t;
    cin >> t;
    while (t--)
    {
        lol n;
        cin >> n;
        lol a[2ll * n];
        for (lol i = 0; i < 2ll * n; i++)
        {
            cin >> a[i];
        }
        sort(a, a + 2ll * n);
        cout << (long long)abs(a[n - 1] - a[n]) << '\n';
    }
}