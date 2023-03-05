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
    lol y[n + 1];
    lol r[n + 1];
    memset(y, 0, sizeof(y));
    memset(r, 0, sizeof(r));
    while (q--)
    {
        lol c;
        cin >> c;
        lol x;
        cin >> x;
        if (c == 1)
        {
            y[x]++;
        }
        else if (c == 2)
            r[x]++;
        else if (y[x] >= 2 || r[x] >= 1)
        {
            cout << "Yes\n";
        }
        else
            cout << "No\n";
    }

    return 0;
}