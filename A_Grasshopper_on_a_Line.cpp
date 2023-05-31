#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol x, k;
        cin >> x >> k;
        if (x % k != 0)
        {
            cout << 1 << '\n';
            cout << x << '\n';
        }
        else
        {
            cout << 2 << '\n';
            cout << x - 1 << " " << 1 << '\n';
        }
    }
}