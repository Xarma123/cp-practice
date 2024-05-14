#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol t;
    cin >> t;
    while (t--)
    {
        lol a, b, c, d;
        cin >> a >> b >> c >> d;
        if (a > b)
            swap(a, b);
        if (c > d)
            swap(c, d);
        if (c > a && c < b)
        {
            if (d > b && d <= 12)
            {
                cout << "YES\n";
            }
            else if (d >= 1 && d < a)
            {
                cout << "YES\n";
            }
            else
                cout << "NO\n";
        }
        else
        {
            swap(c, d);
            if (c > a && c < b)
            {
                if (d > b && d <= 12)
                {
                    cout << "YES\n";
                }
                else if (d >= 1 && d < a)
                {
                    cout << "YES\n";
                }
                else
                    cout << "NO\n";
            }
            else
                cout << "NO\n";
        }
    }

    return 0;
}
