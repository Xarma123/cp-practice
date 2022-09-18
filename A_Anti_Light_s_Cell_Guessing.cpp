#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol n, m;
        cin >> n >> m;
        if (n == 1 && m == 1)
            cout << 0 << endl;
        else if (n == 1 || m == 1)
            cout << 1 << endl;
        else
            cout << 2 << endl;
    }

    return 0;
}