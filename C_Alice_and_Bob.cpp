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
    lol a[n];
    lol gcd = 0;
    lol mx = -1;
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
        mx = max(mx, a[i]);
        gcd = __gcd(gcd, a[i]);
    }
    if (((mx / gcd) - n) % 2 == 0)
    {
        cout << "Bob";
    }
    else
        cout << "Alice";

    return 0;
}