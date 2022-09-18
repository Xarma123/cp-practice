#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, a;
    cin >> n >> a;
    lol ar[n];
    for (lol i = 0; i < n; i++)
    {
        cin >> ar[i];
    }
    a--;
    lol ad = 1;
    lol ans = 0;
    if (ar[a])
        ans++;
    while (a - ad >= 0 || a + ad < n)
    {
        lol c = 0;
        if (a - ad >= 0 && ar[a - ad])
            c++;
        if (a + ad < n && ar[a + ad])
            c++;
        if (c == 2)
            ans += 2;
        if (c == 1 && !(a - ad >= 0 && a + ad < n))
            ans++;
        ad++;
    }
    cout << ans;

    return 0;
}