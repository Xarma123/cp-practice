#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n;
    cin >> n;
    lol a[n];
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    stack<lol> x;
    x.push(-1);
    lol p[n];
    for (lol i = 0; i < n; i++)
    {
        while (x.top() != -1 && a[x.top()] >= a[i])
        {
            x.pop();
        }
        p[i] = x.top();
        x.push(i);
    }
    lol nx[n];
    while (x.top() != -1)
        x.pop();
    for (lol i = 0; i < n; i++)
    {
        while (x.top() != -1 && a[x.top()] > a[i])
        {
            nx[x.top()] = i;
            x.pop();
        }
        x.push(i);
    }
    while (x.top() != -1)
    {
        nx[x.top()] = n;
        x.pop();
    }
    lol dpin[n];
    for (lol i = 0; i < n; i++)
    {
        dpin[i] = 0;
        lol j = p[i];
        if (j >= 0)
            dpin[i] += dpin[j];
        dpin[i] += (i - j) * 1ll * a[i];
    }
    lol dp[n];
    for (lol i = n - 1; i >= 0; i--)
    {
        dp[i] = 0;
        lol j = nx[i];
        if (j < n)
            dp[i] += dp[j];
        dp[i] += (j - i) * 1ll * a[i];
    }
    lol ans = 0;
    lol v = LONG_LONG_MIN;
    for (lol i = 0; i < n; i++)
    {
        if (dpin[i] + dp[i] - a[i] > v)
        {
            v = dpin[i] + dp[i] - a[i];
            ans = i;
        }
    }
    lol b[n];
    b[ans] = a[ans];
    lol mn = a[ans];
    for (lol j = ans - 1; j >= 0; j--)
    {
        mn = min(mn, a[j]);
        b[j] = mn;
    }
    mn = a[ans];
    for (lol j = ans + 1; j < n; j++)
    {
        mn = min(mn, a[j]);
        b[j] = mn;
    }
    for (lol i = 0; i < n; i++)
    {
        cout << b[i] << " ";
    }

   
}