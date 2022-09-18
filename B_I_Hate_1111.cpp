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
        lol x;
        cin >> x;
        lol b = x % 11;
        lol v = x - b * 1ll * 111;
        if (v >= 0 && (v % 11 == 0))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}