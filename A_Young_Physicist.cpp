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
    lol a = 0, b = 0, c = 0;
    while (n--)
    {
        lol a1, a2, a3;
        cin >> a1 >> a2 >> a3;
        a += a1;
        b += a2;
        c += a3;
    }
    if (a == 0 && b == 0 && c == 0)
        cout << "YES";
    else
        cout << "NO";

    return 0;
}