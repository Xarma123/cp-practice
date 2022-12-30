#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n;
    cin >> n;
    lol x[n];
    for (lol i = 0; i < n; i++)
    {
        cin >> x[i];
    }
    lol q;
    cin >> q;
    sort(x, x + n);
    while (q--)
    {
        lol m;
        cin >> m;
        cout << (upper_bound(x, x + n, m) - x) << endl;
    }

    return 0;
}