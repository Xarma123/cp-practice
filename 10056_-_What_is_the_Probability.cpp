#include <bits/stdc++.h>
#define lol long long
using namespace std;

int main()
{
    int t, n, i;
    long double p;
    cin >> t;
    while (t--)
    {
        cin >> n >> p >> i;
        if (p == 0)
            cout << "0.0000" << endl;
        else
            cout << fixed << setprecision(4) << p * powl(1 - p, i - 1) / (long double)(1 - powl(1 - p, n)) << endl;
    }
    return 0;
}