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
    lol ans = 0;
    lol q[n];
    for (lol i = 0; i < n; i++)
    {

        lol a;
        cin >> a;
        ans ^= a;
        q[i] = n - i - 1;
    }
    lol c[n + 1];
    memset(c, 0, sizeof(c));
    for (lol i = 2; i <= n; i++)
    {
        if (n % i != 0)
        {
            c[1]++;
            c[(n % i) + 1]--;
        }
        c[1] += (n - i) / i;
        c[i] -= (n - i) / i;
    }

    for (lol i = 1; i <= n; i++)
    {
        c[i] = c[i] + c[i - 1];
    }
    for (lol i = 0; i < n; i++)
    {
        q[i] += c[i + 1];
    }
    for (lol i = 0; i < n; i++)
    {
        if (q[i] % 2)
        {
            ans ^= (i + 1);
        }
    }
    cout << ans;

    return 0;
}