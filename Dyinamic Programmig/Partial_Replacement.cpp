#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol n, k;
        cin >> n >> k;
        char a[n];
        lol f = -1, l;
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
            if (a[i] == '*')
            {
                if (f == -1)
                    f = i;
                    l = i;
            }
        }
        if (f == l)
        {
            cout << 1 << endl;
        }
        else
        {
            lol ans = 2;
            if (l - f <= k)
            {
                cout << ans << endl;
            }
            else
            {
                lol index = f + k;
                while (1)
                {
                    while (1)
                    {
                        if (a[index] == '*')
                        {
                            ans++;
                            break;
                        }
                        else
                            index--;
                    }
                    if (l - index <= k)
                    {
                        break;
                    }
                    else
                    {
                        index = index + k;
                    }
                }
                cout << ans << endl;
            }
        }
    }

    return 0;
}