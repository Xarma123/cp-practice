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
        lol s = 0;
        for (lol i = 0; i < n; i++)
        {
            lol q;
            cin >> q;
            s += q;
        }
        lol o = s % n;
        cout << o * 1ll * (n - o) << endl;
    }

    return 0;
}