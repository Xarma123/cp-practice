#include <bits/stdc++.h>
#define lol long long
using namespace std;
lol sum(lol n)
{
    return (n * (n + 1)) / 2;
}

lol sum(lol s, lol e)
{
    if (s <= 1)
        return sum(e);

    return sum(e) - sum(s - 1);
}

lol minSplitters(lol k, lol n)
{
    lol st = 1, en = k;

    while (st < en)
    {
        lol md = (st + en) / 2;
        lol s = sum(md, k);

        if (s == n)
            return k - md + 1;

        if (s > n)
            st = md + 1;
        else
            en = md;
    }

    return k - st + 2;
}

int main()
{
    lol n, k;
    cin >> n >> k;

    if (n == 1)
        cout << 0 << "\n";
    else if (n <= k)
        cout << 1 << "\n";
    else
    {
        --k;
        --n;

        if (sum(k) < n)
            cout << -1 << "\n";
        else
            cout << minSplitters(k, n) << "\n";
    }

    return 0;
}