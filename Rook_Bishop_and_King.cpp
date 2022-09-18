#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;
    if (r1 == r2 && c1 == c2)
        cout << "0 "
             << "0 " << 0;
    else
    {
        if (r1 == r2 || c1 == c2)
        {
            cout << "1 ";
        }
        else
            cout << "2 ";

        if (c2 - r2 == c1 - r1 || (c2 + r2 == c1 + r1))

            cout << "1 ";
        else if ((r1 + c1) % 2 != (r2 + c2) % 2) 
            cout << "0 ";

        else
            cout << "2 ";

        cout << max(abs(c1 - c2), abs(r1 - r2));
    }
    return 0;
}