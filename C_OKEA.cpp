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

        if (k == 1)
        {
            cout << "YES" << endl;
            for (lol i = 0; i < n; i++)
            {
                cout << i + 1 << endl;
            }
        }
        else
        {

            if (n % k != 0)
            {
                cout << "NO" << endl;
            }
            else
            {
                cout << "YES" << endl;
                
            }
        }
    }

    return 0;
}