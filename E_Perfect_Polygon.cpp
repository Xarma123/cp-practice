#include <bits/stdc++.h>
#define lol long long
#define M_PI 3.14159265358979323846
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol a, w, h, n;
    cin >> a >> w >> h >> n;
    pair<long double, long double> q[n];
    long double x_ = 0, y_ = 0;
    for (lol i = 0; i < n; i++)
    {
        cin >> q[i].first >> q[i].second;
        x_ += q[i].first;
        y_ += q[i].second;
    }
    x_ = x_ / (long double)n;
    y_ = y_ / (long double)n;
    long double c = cosl(a * M_PI / (long double)180);
    long double s = sinl(a * M_PI / (long double)180);
    long double mny = 1.79769e+308, mxy = 2.22507e-308;
    long double mnx = 1.79769e+308, mxx = 2.22507e-308;
    for (lol i = 0; i < n; i++)
    {
        long double x = q[i].first;
        long double y = q[i].second;
        x = x * c - y * s + x_ * c - y_ * s - x_;
        y = x * s + y * c + x_ * s + y_ * c - y_;
        q[i].first = x;
        q[i].second = y;
        mnx = min(mnx, x);
        mxx = max(mxx, x);
        mny = min(mny, y);
        mxy = max(mxy, y);
    }

    for (lol i = 0; i < n; i++)
    {
        long double x = q[i].first;
        long double y = q[i].second;
        x = x * (long double)((w) / (long double)(mxx - mnx));
        y = y * (long double)((h) / (long double)(mxy - mny));
        cout << fixed << setprecision(9) << x << " " << y << '\n';
    }

    return 0;
}