#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol t;
    cin >> t;
    while (t--)
    {
        lol a, b, c, d;
        cin >> a >> b >> c >> d;
        lol wow = __gcd(a, b);
        a /= wow;
        b /= wow;
        wow = __gcd(c, d);
        c /= wow;
        d /= wow; 
       
        if (a == c && b == d || (a == 0 && c == 0))
            cout << 0 << endl;
        else if (a == 0 || c == 0)
            cout << 1 << endl;
        else
        {
            if (((b * c) % (d * a)) == 0 || ((d * a) % (b * c)) == 0)
                cout << 1 << endl;
            else
                cout << 2 << endl;
        }
    }

    return 0;
}