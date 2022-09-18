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
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        stack<lol> x;
        x.push(a[n - 1]);
        bool f = false;
        for (lol i = n - 2; i >= 0; i--)
        {

            if (a[i] < a[i + 1])
            {
                f = true;
                lol p = i + 1;
                while (a[p] > a[i])
                {
                    p++;
                    if (p == n)
                        break;
                }
                p--;
                swap(a[i], a[p]);
                if (i < n - 1)
                    sort(a + i + 1, a + n);
                break;
            }
        }
        if (!f)
            cout << -1 << endl;
        else
        {
            for (lol i = 0; i < n; i++)
            {
                cout << a[i];
            }
            cout << endl;
        }
    }

    return 0;
}