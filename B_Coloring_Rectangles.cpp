#include <bits/stdc++.h>
#define lol long long
using namespace std;

int main()
{
    lol T;
    cin >> T;
    while (T--)
    {
        lol n, m;
        cin >> n >> m;
        if (n == 1 && m == 1)
            cout << 0 << endl;
        else
            cout << (long long)ceil((n * m * 1ll) / (long double)3) << endl;
    }
    return 0;
}