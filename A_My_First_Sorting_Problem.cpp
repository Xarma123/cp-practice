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
        lol x, y;
        cin >> x >> y;
        cout << min(x, y) << " " << max(x, y) << '\n';
    }

    return 0;
}
