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
        if (n > 19)
            cout << "NO" << endl;
        else
        {
            lol x = 1;
            cout << "YES" << endl;
            for (lol i = 0; i < n; i++)
            {
                cout << x << " ";
                x = x * 1ll * 3;
            }
            cout << endl;
        }
    }

    return 0;
}