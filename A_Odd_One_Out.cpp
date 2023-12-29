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
        lol a, b, c;
        cin >> a >> b >> c;
        if (a == b)
        {
            cout << c << '\n';
        }
        else if (a == c)
        {
            cout << b << '\n';
        }
        else
            cout << a << '\n';
    }

    return 0;
}
