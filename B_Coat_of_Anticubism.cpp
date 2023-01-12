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
    lol s = 0;
    lol mx = 0;
    for (lol i = 0; i < n; i++)
    {
        lol x;
        cin >> x;
        mx = max(mx, x);
        s += x;
    }
    cout << mx - (s - mx) + 1;

    return 0;
}