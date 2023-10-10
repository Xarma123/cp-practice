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
        lol n;
        cin >> n;
        lol c = n - 3;
        if (c % 3 != 0 && c > 2)
        {
            cout << "YES\n";
            cout << 1 << " " << 2 << " " << c << '\n';
        }
        else if ((c - 2) % 3 != 0 && c-2 > 4)
        {
            cout << "YES\n";
            cout << 1 << " " << 4 << " " << c - 2 << '\n';
        }
        else
            cout << "NO\n";
    }
}