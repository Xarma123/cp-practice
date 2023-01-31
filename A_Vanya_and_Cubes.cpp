#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n;
    cin >> n;
    lol s = 0, e = n + 1;
    while (s != e - 1)
    {
        lol m = (s + e) / 2;
        if ((m * 1ll * (m + 1) * 1ll * (m + 2) / 6ll) <= n)
            s = m;
        else
            e = m;
    }
    cout << s;

    return 0;
}