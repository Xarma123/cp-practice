#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol n, k;
        cin >> n >> k;
        if (n % 2 == 0)
        {
            if (k % n == 0)
                cout << n << endl;
            else
                cout << k % n << endl;
        }
        else
        {
            lol ex = 0;
            if (k - n / 2 - 1 >= 0)
                ex++;
            ex += (k - n / 2 - 1) / (n / 2);
            if (ex < 0)
                ex = 0;
            if ((k + ex) % n == 0)
                cout << n << endl;
            else
                cout << (k + ex) % n << endl;
        }
    }

    return 0;
}