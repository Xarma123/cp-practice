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

        lol sum = 0;
        for (lol i = 0; i < n; i++)
        {
            lol T;
            cin >> T;
            sum += T;
        }
        if (sum == n)
        {
            cout << 0 << endl;
        }
        else if (sum > n)
        {
            cout << sum - n << endl;
        }
        else
        {
            cout << 1 << endl;
        }
    }

    return 0;
}