#include <bits/stdc++.h>
#define lol long long
using namespace std;
bool check(lol k, lol n, lol a[])
{
    vector<lol> v(k, 0);
    for (lol i = 0; i < n; i++)
    {
        v[a[i] % k]++;
    }
    for (lol i = 0; i < k; i++)
    {
        if (v[i] <= 1)
            return true;
    }
    return false;
}
//a
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol t;
    cin >> t;
    while (t--)
    {
        lol n;
        cin >> n;
        lol a[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        sort(a, a + n);
        lol i;
        for (i = 0; i < n - 1; i++)
        {
            if (a[i] == a[i + 1])
                break;
        }
        if (i != n - 1)
            cout << "NO" << endl;
        else
        {
            for (i = 2; i <= n; i++)
            {
                if (!check(i, n, a))
                    break;
            }
            if (i == n + 1)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
    }

    return 0;
}