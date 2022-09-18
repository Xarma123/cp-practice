#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol n;
    cin >> n;
    cout << 3 * n + 4 << endl;
    lol y = 0;
    for (lol i = 0; i <= n + 1; i++)
    {
        if (i == 0 || i == n + 1)
        {
            cout << i << " " << y << endl;
            cout << i << " " << y + 1 << endl;
        }
        else
        {
            cout << i << " " << y << endl;
            cout << i << " " << y + 1 << endl;
            cout << i << " " << y + 2 << endl;
            y++;
        }
    }

    return 0;
}