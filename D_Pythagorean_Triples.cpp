#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol n;
        cin >> n;
        lol ans = 0;
        for (lol i = 3; i * i + 1 <= 2 * n; i += 2)
        {
            ans++;
        }
        cout << ans << endl;
    }

    return 0;
}