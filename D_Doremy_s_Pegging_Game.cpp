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
        lol a, b;
        cin >> a >> b;
        a = abs(a);
        b = abs(b);
        if (max(a, b) == min(a, b))
            cout << 2ll * a << '\n';
        else
        {
            cout << 2ll * max(a, b) - 1 << '\n';
        }
    }

    return 0;
}