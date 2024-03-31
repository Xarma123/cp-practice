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
        lol a, b, m;
        cin >> a >> b >> m;
        cout << (m / a) + (m / b) + 2 << '\n';
    }

    return 0;
}
