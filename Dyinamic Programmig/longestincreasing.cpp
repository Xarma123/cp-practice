#include <bits/stdc++.h>
#define lol long long
using namespace std;
lol lis(lol a[], lol n, lol m[])
{
    m[0] = 0;
    for (lol i = 1; i < n; i++)
    {
        lol j;
        for (j = i - 1; j > 0; j--)
        {
            if (a[j - 1] <= a[i - 1])
            {
                break;
            }
        }
        if (j != 0)
        {
            m[i] = max(m[j] + 1, m[i - 1] + 1);
        }
        else
            m[i] = m[i - 1] + 1;
    }

    if (n <= 0)
        return 0;
    lol ans = 1;
    lol i;
    for (i = n - 2; i >= 0; i--)
    {
        if (a[i] <= a[n - 1])
        {
            break;
        }
    }
    if (m[i + 1] == -1)
        m[i + 1] = lis(a, i + 1, m);
    ans += m[i + 1];

    if (m[n - 1] == -1)
        return max(ans, lis(a, n - 1, m));
    return max(ans, m[n - 1]);
}
int main()
{
    lol n;
    cin >> n;
    lol a[n], m[n + 1];

    memset(m, -1, sizeof(m));

    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    cout << lis(a, n, m);

    return 0;
}