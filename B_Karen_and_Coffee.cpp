#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol n, k, q;
    cin >> n >> k >> q;

    lol c[200001];

    for (lol i = 0; i <= 200000; i++)
    {
        c[i] = 0;
    }

    for (lol i = 0; i < n; i++)
    {
        lol a, b;
        cin >> a >> b;
        c[a]++;
        if (b + 1 <= 200000)
            c[b + 1]--;
    }

    for (lol i = 1; i <= 200000; i++)
    {
        c[i] += c[i - 1];
    }

    for (lol i = 0; i <= 200000; i++)
    {
        if (c[i] >= k)
            c[i] = 1;
        else
            c[i] = 0;
    }

    for (lol i = 1; i <= 200000; i++)
    {
        c[i] += c[i - 1];
    }

    while (q--)
    {
        lol a, b;
        cin >> a >> b;
        cout << c[b] - c[a - 1] << endl;
    }

    return 0;
}