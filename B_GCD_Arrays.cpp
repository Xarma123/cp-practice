#include <bits/stdc++.h>
#define lol long long
using namespace std;

int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol l, r, k;
        cin >> l >> r >> k;

        if (l == r)
        {

            if (l <= 1)
            {
                cout << "NO" << endl;
            }
            else
                cout << "YES" << endl;
        }
        else
        {
            if (l % 2 != 0 && r % 2 != 0)
            {
                lol c = (r - l) / 2;
                if (k > c)
                    cout << "YES" << endl;
                else
                {
                    cout << "NO" << endl;
                }
            }
            else if (l % 2 != 0 && r % 2 == 0)
            {
                lol c = (r - l + 1) / 2;
                if (k >= c)
                    cout << "YES" << endl;
                else
                {
                    cout << "NO" << endl;
                }
            }
            else if (l % 2 == 0 && r % 2 != 0)
            {
                lol c = (r - l + 1) / 2;
                if (k >= c)
                    cout << "YES" << endl;
                else
                {
                    cout << "NO" << endl;
                }
            }
            else
            {
                lol c = (r - l) / 2;
                if (k >= c)
                    cout << "YES" << endl;
                else
                {
                    cout << "NO" << endl;
                }
            }
        }
    }

    return 0;
}