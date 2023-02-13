#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol v;
    cin >> v;
    lol a[9];
    lol mn = 1e6;
    for (lol i = 0; i < 9; i++)
    {
        cin >> a[i];
        mn = min(mn, a[i]);
    }
    lol c = v / mn;
    for (lol i = 0; i < c; i++)
    {
        lol j;
        for (j = 8; j >= 0; j--)
        {
            if (v >= a[j] && ((v - a[j]) / mn) >= c - i - 1)
            {
                break;
            }
        }
        cout << j + 1;
        v -= a[j];
    }
    if (c == 0)
        cout << -1;

    return 0;
}