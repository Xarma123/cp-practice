#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol a, b, c;
        cin >> a >> b >> c;
        bool solved = false;
        if ((2ll * (long long)b - (long long)c) % a == 0 && (2ll * (long long)b - (long long)c) > 0)
        {
            if (2ll * (long long)b - c != 0)
            {
                cout << "YES" << endl;
                solved = true;
            }
        }
        if (((long long)a + (long long)c) % (2ll * (long long)b) == 0 && (!solved) && ((long long)a + (long long)c) > 0)
        {
            if ((long long)a + (long long)c != 0)
            {
                cout << "YES" << endl;
                solved = true;
            }
        }
        if ((2ll * (long long)b - a) % c == 0 && (!solved) && (2ll * (long long)b - a) > 0)
        {
            if (2ll * (long long)b - a != 0)
            {
                cout << "YES" << endl;
                solved = true;
            }
        }
        if (!solved)
            cout << "NO" << endl;
    }

    return 0;
}