#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, x, y;
    cin >> n >> x >> y;
    lol a[n];
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (lol i = 0; i < n; i++)
    {
        bool f = true;
        for (lol j = i - 1; j >= i - x && j >= 0; j--)
        {
            if (a[i] >= a[j])
                f = false;
        }
        for (lol j = i + 1; j < n && j <= i + y; j++)
        {
            if (a[i] >= a[j])
                f = false;
        }
        if (f)
        {
            cout << i + 1;
            break;
        }
    }
}