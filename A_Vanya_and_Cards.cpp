#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, x;
    cin >> n >> x;
    lol s = 0;
    while (n--)
    {
        lol c;
        cin >> c;
        s += c;
    }
    s = abs(s);
    cout << (s / x) + (s % x > 0);

    return 0;
}