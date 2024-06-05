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
        if ((a + b + c) % 2)
        {
            cout << -1 << '\n';
        }
        else if (c >= a + b)
        {
            cout << (a + b) - ((c-a-b) % 2) << '\n';
        }
        else
        {
            cout << (a + b + c) / 2ll << '\n';
        }
    }

    return 0;
}
