#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, q;
    cin >> n >> q;
    lol p[n];
    for (lol i = 0; i < n; i++)
    {
        cin >> p[i];
    }
    sort(p, p + n);
    lol c[n + 1];
    c[0] = 0;
    for (lol i = 0; i < n; i++)
    {
        c[i + 1] = c[i] + p[i];
    }
    while (q--)
    {
        lol x, y;
        cin >> x >> y;
        cout << c[n - x + y] - c[n - x] << endl;
    }

    return 0;
}