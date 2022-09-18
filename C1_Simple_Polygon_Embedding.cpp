#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol T;
    cin >> T;
    while (T--)
    {
        lol n;
        cin >> n;

        long double pi = acosl(-1);
        long double a = (long double)(pi) / ((long double)2 * (long double)n);
        cout << setprecision(7) << 1 / ((long double)sinl(a)) << endl;
    }
    return 0;
}