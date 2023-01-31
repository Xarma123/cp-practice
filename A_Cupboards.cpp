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
    lol a = 0, b = 0;
    for (lol i = 0; i < n; i++)
    {
        lol l, r;
        cin >> l >> r;
        a += l;
        b += r;
    }
    cout << min(a, n - a) + min(b, n - b);

    return 0;
}