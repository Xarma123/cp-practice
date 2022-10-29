#include <bits/stdc++.h>
#define lol long double
using namespace std;
bool check(lol x, lol y, vector<lol> f)
{
    if (f.size() == 3)
    {
        return (f[2] * f[2] > powl(x - f[0], 2) + powl(y - f[1], 2));
    }
    if (x > f[0] && y < f[1] && x < f[2] && y > f[3])
        return true;
    return false;
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<vector<lol>> fig;
    char c;
    while (1)
    {
        cin >> c;
        if (c == '*')
            break;
        if (c == 'r')
        {
            lol x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            fig.push_back({x1, y1, x2, y2});
        }
        else
        {
            lol x, y, r;
            cin >> x >> y >> r;
            fig.push_back({x, y, r});
        }
    }
    lol q = 1;
    while (1)
    {
        lol x, y;
        cin >> x >> y;
        if (abs(x - 9999.9) <= 1e-9 && abs(y - 9999.9) <= 1e-9)
            break;

        bool f = true;
        for (lol i = 0; i < fig.size(); i++)
        {
            if (check(x, y, fig[i]))
            {
                cout << "Point " << q << " is contained in figure " << i + 1 << endl;
                f = false;
            }
        }
        if (f)
        {
            cout << "Point " << q << " is not contained in any figure" << endl;
        }

        q++;
    }

    return 0;
}