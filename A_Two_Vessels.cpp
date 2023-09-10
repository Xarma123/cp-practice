#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol t;
    cin >> t;
    while (t--)
    {
        lol a, b, c;
        cin >> a >> b >> c;
        if (a < b)
            swap(a, b);
        if ((a + b) % 2 == 0)
        {
            cout << (a - ((a + b) / 2)) / c + (((a - ((a + b) / 2)) % c) > 0) << '\n';
        }
        else
        {
            cout << (a - ((a + b + 1) / 2)) / c + 1 << '\n';
        }
    }
}