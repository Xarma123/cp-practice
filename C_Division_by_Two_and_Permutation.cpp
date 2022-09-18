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
        lol c = n;
        while (c--)
        {
            cin >> a[c];
        }
        sort(a, a + n);
        bool arr[n];
        for (lol i = 0; i < n; i++)
        {
            arr[i] = false;
        }
        for (lol i = 0; i < n; i++)
        {

            while (a[i] > n)
            {
                a[i] = a[i] / 2;
            }
            if (a[i] > 0)
            {
                while (arr[a[i] - 1])
                {
                    a[i] = a[i] / 2;
                    if (a[i] == 0)
                        break;
                }
                if (a[i] != 0)
                    arr[a[i] - 1] = true;
            }
        }
        lol i;
        for (i = 0; i < n; i++)
        {
            if (!arr[i])
                break;
        }
        if (i == n)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}