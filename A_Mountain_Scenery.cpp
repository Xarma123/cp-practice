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
    lol a[2 * n + 1];
    for (lol i = 0; i < 2 * n + 1; i++)
    {
        cin >> a[i];
    }
    for (lol i = 1; i < 2 * n + 1; i += 2)
    {
        if (a[i] - 1 > a[i - 1] && a[i] - 1 > a[i + 1] && k)
        {
            k--;
            a[i]--;
        }
    }
    for (lol i = 0; i < 2 * n + 1; i++)
        cout << a[i] << " ";

    return 0;
}