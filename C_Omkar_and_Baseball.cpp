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
        lol a[n];
        lol ans = 0;
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
            if (a[i] == i + 1)
                ans++;
        }
        lol i = 0;
        while (a[i] == i + 1)
        {
            i++;
            if (i == n)
                break;
        }
        lol c = i;
        i = n - 1;
        while (a[i] == i + 1)
        {
            i--;
            if (i < 0)
                break;
        }
        c += n - 1 - i;

        if (ans == n)
            cout << 0 << endl;
        else if (ans > 0)
        {
            if (ans - c > 0)
                cout << 2 << endl;
            else
                cout << 1 << endl;
        }
        else
            cout << 1 << endl;
    }

    return 0;
}