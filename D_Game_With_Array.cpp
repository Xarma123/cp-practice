#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol n, s;
    cin >> n >> s;
    lol a[n];
    lol c = 0;
    bool f = true;
    for (lol i = 0; i < n; i++)
    {
        if (i != n - 1)
        {
            a[i] = 2;
            c += 2;
        }
        else
        {
            if (s - c <= 1)
            {
                f = false;
            }
            else
                a[i] = s - c;
        }
    }
    if (!f)
        cout << "NO" << endl;
    else
    {
        cout << "YES" << endl;
        for (lol i = 0; i < n; i++)
        {
            cout << a[i] << " ";
        }
        cout << endl;
        cout << 1 << endl;
    }

    return 0;
}