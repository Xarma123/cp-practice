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
        lol n, m;
        cin >> n >> m;
        if (n == 1 && m == 1)
            cout << 0 << endl;
        else
            cout << n - 1 + m - 1 + min(n, m) << endl;
    }

    return 0;
}