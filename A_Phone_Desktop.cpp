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
        lol x, y;
        cin >> x >> y;
        lol s = y / 2;
        lol ex = s * 1ll * 7;
        if (y % 2)
        {
            s++;
            ex += 11;
        }
        if (ex < x)
        {
            x -= ex;
            s += (x + 14ll) / 15ll;
        }
        cout << s << '\n';
    }

    return 0;
}
