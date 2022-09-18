#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol a1, a2, a3;
        cin >> a1 >> a2 >> a3;
        lol s = a1 + a3;
        if (s == 2 * a2)
        {
            cout << 0 << endl;
        }
        else if (s > 2 * a2)
        {
            lol ans;
            lol c = (s - 2 * a2) / 3;
            ans = s - c - 2 * (a2 + c);
            ans = min(ans, abs(s - c - 1 - 2 * (a2 + c + 1)));
            cout<<ans<<endl;
        }
        else
        {
            lol ans;
            lol c = (2 * a2 - s) / 3;
            ans = -s - c + 2 * (a2 - c);
            ans = min(ans, abs(2 * (a2 - c - 1) - s - c - 1));
            cout<<ans<<endl;
        }
    }

    return 0;
}