#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol w, h;
        cin >> w >> h;
        lol ans = 0;
        set<lol> x;
        lol h0;
        cin >> h0;
        while (h0--)
        {
            lol t;
            cin >> t;
            x.insert(t);
        }
        lol area = (*x.rbegin()) - (*x.begin());
        area = area * h;
        ans = max(ans, area);
        x.clear();
        cin >> h0;
        while (h0--)
        {
            lol t;
            cin >> t;
            x.insert(t);
        }
        area = (*x.rbegin()) - (*x.begin());
        area = area * h;
        ans = max(ans, area);
        x.clear();
        cin >> h0;
        while (h0--)
        {
            lol t;
            cin >> t;
            x.insert(t);
        }
        area = (*x.rbegin()) - (*x.begin());
        area = area * w;
        ans = max(ans, area);
        x.clear();
        cin >> h0;
        while (h0--)
        {
            lol t;
            cin >> t;
            x.insert(t);
        }
        area = (*x.rbegin()) - (*x.begin());
        area = area * w;
        ans = max(ans, area);

        cout << ans << endl;
    }

    return 0;
}