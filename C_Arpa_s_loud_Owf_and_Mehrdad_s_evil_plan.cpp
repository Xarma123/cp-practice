#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n;
    cin >> n;
    lol a[n];
    bool vis[n];
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
        a[i]--;
        vis[i] = false;
    }
    lol lcm = 1;
    lol i;
    for (i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            lol c = 1;
            lol j = i;
            vis[j] = true;
            while (!vis[a[j]])
            {
                j = a[j];
                vis[j] = true;
                c++;
                
            }
            if (a[j] != i)
            {
                cout << -1;
                break;
            }
            if (c % 2 == 0)
                c /= 2;

            lcm = lcm * 1ll * c / __gcd(lcm, c);
        }
    }
    if (i == n)
        cout << lcm;

    return 0;
}