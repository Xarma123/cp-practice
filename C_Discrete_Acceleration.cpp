#include <bits/stdc++.h>
#define lol long long
using namespace std;
vector<lol> v;
bool ans(long double t, lol l)
{
    long double x1 = 0;
    long double t1 = 0;
    lol speed = 1;
    lol p = 0;
    for (lol i = 0; i < v.size(); i++)
    {
        if (t1 + (v[i] - p) / (long double)speed <= t)
        {
            t1 += (v[i] - p) / (long double)speed;
            p = v[i];
            speed++;
        }
        else
            break;
    }
    x1 = p + (t - t1) * speed;
    long double x2 = l;
    long double t2 = 0;
    speed = 1;
    p = l;
    for (lol i = v.size() - 1; i >= 0; i--)
    {
        if (t2 + (p - v[i]) / (long double)speed <= t)
        {
            t2 += (p - v[i]) / (long double)speed;
            p = v[i];
            speed++;
        }
        else
            break;
    }
    x2 = p - (t - t2) * speed;
    return x1 <= x2;
}
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol n, l;
        cin >> n >> l;

        for (lol i = 0; i < n; i++)
        {
            lol t;
            cin >> t;
            v.push_back(t);
        }
        long double s = 0;
        long double e = 1e18;
        while (e - s > 1e-10)
        {
            long double m = (s + e) / (long double)2;
            if (ans(m, l))
                s = m;
            else
                e = m;
        }
        cout <<setprecision(11)<< s << endl; 
        v.clear();
    }

    return 0;
}