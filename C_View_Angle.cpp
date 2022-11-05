#include <bits/stdc++.h>
#define lol long double
using namespace std;
#define PI 3.14159265
long double aatan(long double a)
{
    return ((atan(a) * 180) / PI);
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    lol n;
    cin >> n;
    vector<lol> ang;
    for (lol i = 0; i < n; i++)
    {
        lol x, y;
        cin >> x >> y;
        if (x == 0 && y >= 0)
        {
            ang.push_back((long double)90);
        }
        else if (x == 0 && y < 0)
        {
            ang.push_back((long double)270);
        }
        else if (y == 0 && x >= 0)
        {
            ang.push_back((long double)0);
        }
        else if (y == 0 && x < 0)
        {
            ang.push_back((long double)180);
        }
        else if (x > 0 && y > 0)
        {
            ang.push_back(aatan(y / x));
        }
        else if (x < 0 && y > 0)
        {
            ang.push_back(180 - aatan(abs(y) / abs(x)));
        }
        else if (x < 0 && y < 0)
        {
            ang.push_back(180 + aatan(abs(y) / abs(x)));
        }
        else if (x > 0 && y < 0)
        {
            ang.push_back(360 - aatan(abs(y) / abs(x)));
        }
    }
    sort(ang.begin(), ang.end());
    lol ans = DBL_MAX;
    for (lol i = 0; i < ang.size() - 1; i++)
    {
        ans = min(ans, 360 - ang[i + 1] + ang[i]);
    }
    ans = min(ans, ang.back() - ang[0]);
    cout << fixed << setprecision(8) << ans;

    return 0;
}