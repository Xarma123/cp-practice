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
        lol a[n];
        lol s = 0;
        lol k = 0;
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
            s += a[i];
            k ^= a[i];
        }
        cout << 2 << endl;
        cout << k << " " << (s + k) << endl;
    }

    return 0;
}