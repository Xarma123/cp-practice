#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol l, p, q;
    cin >> l >> p >> q;
    long double t = l / (long double)(p + q);
    long double x = p * t;
    cout << fixed << setprecision(10) << x;

    return 0;
}