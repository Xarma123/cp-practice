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
        if (n == 1)
            cout << 0 << endl;
        else if (n % 2 == 0)
        {
            if (n == 2)
                cout << 1 << endl;
            else
                cout << 2 << endl;
        }
        else
        {
            if (n != 3)
                cout << 3 << endl;
            else
                cout << 2 << endl;
        }
    }

    return 0;
}