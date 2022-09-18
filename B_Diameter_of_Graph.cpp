#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol n, m, k;
        cin >> n >> m >> k;
        if (n * (n - 1) / 2 < m || n - 1 > m)
        {
            cout << "NO" << endl;
        }
        else if (n == 1)
        {
            if (k > 1)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
        else if (m<(n-1)*n/2)
        {
            if (k > 3)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
        else
        {
            if (k > 2)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
    }

    return 0;
}