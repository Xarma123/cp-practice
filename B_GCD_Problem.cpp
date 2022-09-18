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
        lol i;
        for (i = 2; i != n - 1 - i && n - 1 - i > 1; i++)
        {
            if (__gcd(i, n - 1 - i) == 1)
            {
                break;
            }
        }

        cout << i << " " << n - 1 - i << " " << 1 << endl;
    }

    return 0;
}