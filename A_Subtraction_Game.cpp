#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol a, b;
        cin >> a >> b;
        if (a > 1)
            cout << 1 << '\n';
        else if (b > 2)
        {
            cout << 2 << '\n';
        }
        else
        {
            cout << 3 << '\n';
        }
    }
}