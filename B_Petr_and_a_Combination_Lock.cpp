#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol n;
    cin >> n;
    lol a[n];

    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    bool flag = false;

    for (lol i = 0; i < pow(2, n); i++)
    {
        lol s = 0;
        for (lol j = 0; j < n; j++)
        {
            if (i & (1 << j))
            {
                s += a[j];
            }
            else
                s -= a[j];
        }
        if (s % 360 == 0)
        {
            flag = true;
            break;
        }
    }
    if (flag)
        cout << "YES";
    else
        cout << "NO";

    return 0;
}