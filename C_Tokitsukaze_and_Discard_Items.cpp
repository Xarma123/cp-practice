#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, m, k;
    cin >> n >> m >> k;
    lol p[m];
    for (lol i = 0; i < m; i++)
    {
        cin >> p[i];
    }

    lol sub = 0;
    lol ans = 0;
    lol i = 0;
    while (i < m)
    {
        ans++;
        lol v = (p[i] - sub + k - 1) / k;
        lol j = i + 1;
        while (j < n && v == ((p[j] - sub + k - 1) / k))
            j++;
        sub += j - i;
        i = j;
    }
    cout << ans;
}