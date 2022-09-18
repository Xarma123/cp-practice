#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol n;
    cin >> n;
    lol a[n];
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    lol ng[n + 1];
    ng[0] = 0;
    for (lol i = 1; i <= n; i++)
    {
        ng[i] = ng[i - 1] + (a[i - 1] > 0 ? 0 : 1);
    }
    lol e = 1, o = 0;

    lol ansneg = 0;
    for (lol i = 1; i <= n; i++)
    {
        if (ng[i] % 2 == 0)
        {
            ansneg += o;
            e++;
        }
        else
        {
            ansneg += e;
            o++;
        }
    }
    cout << ansneg << " " << (n) * (n + 1) / 2 - ansneg;

    return 0;
}