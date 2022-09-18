#include <bits/stdc++.h>
#define lol long double
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<pair<pair<lol, lol>, pair<lol, lol>>> rec;
    lol er = 1e-6;
    while (1)
    {
        char c;
        cin >> c;
        if (c == '*')
            break;
        lol x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        rec.push_back({{x1, y1}, {x2, y2}});
    }
    lol p = 1;
    while (1)
    {
        lol x, y;
        cin >> x >> y;
        if (abs(x - 9999.9) <= er && abs(y - 9999.9) <= er)
            break;
        bool f = true;
        lol c = 1;
        for (auto e : rec)
        {
            lol x1 = e.first.first;
            lol x2 = e.second.first;

            if (x - x1 > er && x - x2 < er)
            {
                lol y1 = e.first.second;
                lol y2 = e.second.second;
                if (y2 - y < er && y1 - y > er)
                {
                    f = false;
                    cout << "Point " << p << " is contained in figure " << c << endl;
                }
            }
            c++;
        }
        if (f)
        {
            cout << "Point " << p << " is not contained in any figure" << endl;
        }
        p++;
    }

    return 0;
}