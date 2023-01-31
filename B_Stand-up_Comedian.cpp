#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol t;
    cin >> t;
    while (t--)
    {
        lol a1, a2, a3, a4;
        cin >> a1 >> a2 >> a3 >> a4;
        if (a2 < a3)
            swap(a2, a3);
        if (a1)
            cout << a1 + 2ll * a3 + min(a2 - a3 + a4, a1 + 1) << '\n';
        else
            cout << 1 << '\n';
    }

    return 0;
}