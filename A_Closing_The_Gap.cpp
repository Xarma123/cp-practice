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
        lol c = n;
        lol s = 0;
        while (c--)
        {
            lol t;
            cin >> t;
            s += t;
        }
        if (s % n == 0)
            cout << 0 << endl;
        else
            cout << 1 << endl;
    }

    return 0;
}