#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, m;
    cin >> n >> m;
    lol a[n];
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    lol b[n];
    for (lol i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    sort(a, a + n);
    sort(b, b + n);
    set<lol> e;
    for (lol j = 0; j < n; j++)
    {
        if (a[0] == b[j])
        {
            e.insert(0);
        }
        else if (a[0] < b[j])
        {
            e.insert(b[j] - a[0]);
        }
        else
        {
            e.insert(m + b[j] - a[0]);
        }
    }

    for (auto q : e)
    {
        lol c[n];
        for (lol i = 0; i < n; i++)
        {
            c[i] = (a[i] + q) % m;
        }
        sort(c, c + n);
        lol i;
        for (i = 0; i < n; i++)
        {
            if (b[i] != c[i])
                break;
        }
        if (i == n)
        {
            cout << q;
            break;
        }
    }
}