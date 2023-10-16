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
        if (a == b && b == c)
        {
            cout << "YES\n";
            continue;
        }

        lol s = a + b + c;
        if (s % 4 == 0)
        {
            s /= 4;
            if (a % s == 0 && b % s == 0 && c % s == 0)
            {
                cout << "YES\n";
                continue;
            }
        }
        s = a + b + c;
        if (s % 5 == 0)
        {
            s /= 5;
            if (a % s == 0 && b % s == 0 && c % s == 0)
            {
                cout << "YES\n";
                continue;
            }
        }
        s = a + b + c;
        if (s % 6 == 0)
        {
            s /= 6;
            if (a % s == 0 && b % s == 0 && c % s == 0)
            {
                cout << "YES\n";
                continue;
            }
        }
        cout << "NO\n";
    }
}