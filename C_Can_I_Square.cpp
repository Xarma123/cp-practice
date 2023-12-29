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
        lol n;
        cin >> n;
        lol sum = 0;
        while (n--)
        {
            lol v;
            cin >> v;
            sum += v;
        }
        lol v = floorl(sqrtl(sum));
        if (v * 1ll * v == sum)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}
