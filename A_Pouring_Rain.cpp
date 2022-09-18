#include <bits/stdc++.h>
#define lol long long
#define M_PI 3.14159265358979323846
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long double d, h, v, e;
    cin >> d >> h >> v >> e;
    long double pi = M_PI;
    long double speed = v - ((pi * d * d / 4) * e);
    if (speed <= 0)
    {
        cout << "NO";
    }
    else
    {
        cout << "YES" << endl;
        long double ans = (pi * d * d / 4) * h / speed;
        cout << setprecision(10) << ans;
    }

    return 0;
}