#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol n, m, k;
    cin >> n >> m >> k;
    lol ar[n];
    for (lol i = 0; i < n; i++)
    {
        ar[i] = n - 1;
    }
    set<lol> x;
    for (lol i = 0; i < m; i++)
    {
        lol a, b;
        cin >> a >> b;
        if (a == 1)
            x.insert(b);
        if (b == 1)
            x.insert(a);
        ar[a - 1]--;
        ar[b - 1]--;
    }
    lol c = 0;
    for (lol i = 2; i <= n; i++)
    {
        if (!x.count(i))
        {
            if (ar[i - 1] == 1)
                c++;
        }
    }

    bool f = true;
    if (c > k)
    {
        f = false;
    }
    if (ar[0] < k && f)
    {
        f = false;
    }
    if (f)
    {
        for (lol i = 1; i < n; i++)
        {
            if (ar[i] < 1)
            {
                f = false;
                break;
            }
        }
    }
    if (f)
    {
        cout << "possible";
    }
    else
        cout << "impossible";

    return 0;
}