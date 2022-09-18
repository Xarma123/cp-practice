#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long double x;
    while (1)
    {
        cin >> x;
        if (x == 0)
            break;
        long long s = powl(x, 1 / (long double)3);
        // cout << s << endl;
        long double dx = (x - (long double)(s * s * s)) / (long double)(3 * s * s);
        cout << fixed << setprecision(4) << (long double)(s + dx) << endl;
    }

    return 0;
}