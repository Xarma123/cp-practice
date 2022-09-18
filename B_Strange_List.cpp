#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol n, x;
        cin >> n >> x;
        vector<lol> a;
        lol ans = 0;
        for (lol i = 0; i < n; i++)
        {
            lol t;
            cin >> t;
            a.push_back(t);
            ans += t;
        }

        bool flag = true;

        for (lol i = 0; i < n; i++)
        {
            if (a[i] % x == 0)
            {

                lol n = a[i] / x;

                a.push_back(n);
            }
            else
            {
                flag = false;
                break;
            }
        }

        if (flag)
        {
            lol times = x;
            lol k = INT_MAX;
            for (lol i = n; i < a.size(); i++)
            {
                if (i == k)
                {
                    times = x * times;
                    k = INT_MAX;
                }

                ans += times * a[i];

                if (a[i] % x == 0 && flag)
                {
                    lol n = a[i] / x;
                    if (k == INT_MAX)
                    {
                        k = a.size();
                    }

                    a.push_back(n);
                }
                else
                {
                    flag = false;
                }
            }
        }
        else
        {
            for (lol i = n; i < a.size(); i++)
            {
                ans += x * a[i];
            }
        }

        cout << ans << endl;
    }

    return 0;
}