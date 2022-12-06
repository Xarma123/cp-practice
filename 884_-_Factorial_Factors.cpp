#include <bits/stdc++.h>
#define lol int
using namespace std;
#define MAXN 1000001
lol dp[MAXN];
lol v[MAXN];
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (lol i = 0; i < MAXN; i++)
    {
        dp[i] = i;
    }
    for (lol i = 2; i < MAXN; i += 2)
    {
        dp[i] = 2;
    }
    for (lol i = 3; i < MAXN; i += 2)
    {
        if (dp[i] == i)
        {
            for (lol j = i * 1ll * i; j < MAXN; j += i)
            {
                dp[j] = i;
            }
        }
    }
    v[2] = 1;
    v[1] = 0;
    v[0] = 0;
    for (lol i = 3; i < MAXN; i++)
    {
        v[i] = v[i / dp[i]] + 1;
    }
    for (lol i = 2; i < MAXN; i++)
    {
        v[i] += v[i - 1];
    }

    lol n;
    cin >> n;
    cout << v[n] << endl;

    return 0;
}