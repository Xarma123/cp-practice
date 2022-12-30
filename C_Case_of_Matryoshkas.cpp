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
    lol ans = 0;
    lol c = 0;
    while (k--)
    {
        lol m;
        cin >> m;
        lol a[m];
        for (lol i = 0; i < m; i++)
        {
            cin >> a[i];
        }
        lol q = 0;
        lol i = 0;
        while (i < m && a[i] == i + 1)
            i++;
        if (i)
            q++;
        for (; i < m; i++)
        {
            q++;
        }
        ans += q - 1;
        c += q;
    }
    ans += c - 1;
    cout << ans;

    return 0;
}