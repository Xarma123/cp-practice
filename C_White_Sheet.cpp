#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    lol x3, y3, x4, y4;
    cin >> x3 >> y3 >> x4 >> y4;
    lol x5, y5, x6, y6;
    cin >> x5 >> y5 >> x6 >> y6;
    bool ans = true;
    for (lol i = y1; i <= y2; i++)
    {
        // x1 -- x2
        lol l1 = -1, r1 = -1;
        if (i >= y3 && i <= y4)
        {
            l1 = x3, r1 = x4;
        }

        lol l2 = -1, r2 = -1;
        if (i >= y5 && i <= y6)
        {
            l2 = x5;
            r2 = x6;
        }
        bool c = false;
        if (x1 >= l1 && x2 <= r1)
            c = true;
        if (x1 >= l2 && x2 <= r2)
            c = true;
        if (!(r1 < l2 || r2 < l1))
        {
            l1 = min(l1, l2);
            r1 = max(r1, r2);
            if (x1 >= l1 && x2 <= r1)
                c = true;
        }
        if (!c)
        {
            ans = false;
        }
    }

    swap(x1, y1);
    swap(x2, y2);
    swap(x3, y3);
    swap(x4, y4);
    swap(x5, y5);
    swap(x6, y6);
    for (lol i = y1; i <= y2; i++)
    {
        // x1 -- x2
        lol l1 = -1, r1 = -1;
        if (i >= y3 && i <= y4)
        {
            l1 = x3, r1 = x4;
        }

        lol l2 = -1, r2 = -1;
        if (i >= y5 && i <= y6)
        {
            l2 = x5;
            r2 = x6;
        }
        bool c = false;
        if (x1 >= l1 && x2 <= r1)
            c = true;
        if (x1 >= l2 && x2 <= r2)
            c = true;
        if (!(r1 < l2 || r2 < l1))
        {
            l1 = min(l1, l2);
            r1 = max(r1, r2);
            if (x1 >= l1 && x2 <= r1)
                c = true;
        }
        if (!c)
        {
            ans = false;
        }
    }

    if (!ans)
        cout << "YES\n";
    else
        cout << "NO\n";
}