#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol t;
    cin >> t;
    while (t--)
    {
        lol x1, y1;
        cin >> x1 >> y1;
        lol x2, y2;
        cin >> x2 >> y2;
        lol x3, y3;
        cin >> x3 >> y3;
        lol x4, y4;
        cin >> x4 >> y4;
        cout << max(abs(y1 - y2), abs(y1 - y3)) * 1ll * max(abs(x1 - x2), abs(x1 - x3)) << '\n';
    }

    return 0;
}
