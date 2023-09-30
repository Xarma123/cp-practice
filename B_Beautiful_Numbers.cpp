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
        lol a[n];
        lol in[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
            in[a[i] - 1] = i;
        }
        lol l = LONG_LONG_MAX;
        lol r = LONG_LONG_MIN;
        for (lol i = 0; i < n; i++)
        {
            l = min(l, in[i]);
            r = max(r, in[i]);
            if (r - l + 1 == i + 1)
                cout << 1;
            else
                cout << 0;
        }
        cout << '\n';
    }
}