#include <bits/stdc++.h>
#define lol long double
using namespace std;
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol n, g, b;
        cin >> n >> g >> b;
        if (b * (ceil(ceil(n / 2) / g) - 1) >= n - ceil(n / 2))
            cout << (long long)(b * (ceil(ceil(n / 2) / g) - 1) + ceil(n / 2)) << endl;
        else
            cout << (long long)n << endl;
    }

    return 0;
}