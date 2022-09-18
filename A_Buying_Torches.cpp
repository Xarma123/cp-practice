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
        lol x, y, k;
        cin >> x >> y >> k;
        lol l = ceill((k * 1ll * y + k - 1) / (long double)(x - 1));
        cout << l + k << endl;
    }
    return 0;
}