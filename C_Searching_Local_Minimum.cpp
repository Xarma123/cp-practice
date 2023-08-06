#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n;
    cin >> n;
    if (n == 1)
    {
        cout <<"! "<< 1 << endl;
    }
    else
    {
        lol s = 1, e = n;
        lol ans;
        while (s < e)
        {
            lol m = (s + e) / 2;
            if (m == 1)
            {
                lol a, b;
                cout << "? " << 1 << endl;
                cin >> a;
                cout << "? " << 2 << endl;
                cin >> b;
                if (a < b)
                {
                    ans = 1;
                    break;
                }
                else
                {
                    s = m + 1;
                }
            }
            else if (m == n)
            {
                lol a, b;
                cout << "? " << n << endl;
                cin >> a;
                cout << "? " << n - 1 << endl;
                cin >> b;
                if (a < b)
                {
                    ans = n;
                    break;
                }
                else
                {
                    e = m - 1;
                }
            }
            else
            {
                lol a, b, c;
                cout << "? " << m - 1 << endl;
                cin >> a;
                cout << "? " << m << endl;
                cin >> b;
                cout << "? " << m + 1 << endl;
                cin >> c;
                if (a > b && b < c)
                {
                    ans = m;
                    break;
                }
                else if (a > b && b > c)
                {
                    s = m + 1;
                }
                else
                    e = m - 1;
            }
        }
        if (s >= e)
            cout << "! " << s << endl;
        else
            cout << "! " << ans << endl;
    }
}