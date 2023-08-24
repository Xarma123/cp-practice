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
        lol a, b;
        cin >> a >> b;
        if (a == b)
            cout << 0 << '\n';
        else if (a < b)
        {
            if ((b - a) % 2)
                cout << 1 << '\n';
            else
                cout << 2 << '\n';
        }
        else
        {
            if ((a - b) % 2)
                cout << 2 << '\n';
            else
                cout << 1 << '\n';
        }
    }
}