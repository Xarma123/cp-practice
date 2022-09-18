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
        lol a[30] = {0};
        for (lol i = 0; i < n; i++)
        {
            lol t;
            cin >> t;
            for (lol i = 0; i < 30; i++)
            {
                if (t & (1 << i))
                {
                    a[i]++;
                }
            }
        }

        lol k = 1;
        cout << 1 << " ";
        k++;
        while (k <= n)
        {
            bool flag = true;
            for (lol i = 0; i < 30; i++)
            {
                if (a[i] % k != 0)
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
                cout << k << " ";
            k++;
        }
        cout << endl;
    }

    return 0;
}