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
        lol m;
        cin >> m;
        lol s = 1;
        while (s * 1ll * 10 <= m)
            s = s * 1ll * 10;
        cout << m - s << endl;
    }

    return 0;
}