#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        string a;
        cin >> a;
        lol n = a.size();
        if ((a[n - 1] - '0') % 2 == 0)
        {
            cout << 0 << endl;
        }
        else if ((a[0] - '0') % 2 == 0)
        {
            cout << 1 << endl;
        }
        else
        {
            bool f = false;
            for (lol i = 1; i < n - 1; i++)
            {
                if ((a[i] - '0') % 2 == 0)
                {
                    f = true;
                    break;
                }
            }
            if (!f)
            {
                cout << -1 << endl;
            }
            else
                cout << 2 << endl;
        }
    }

    return 0;
}