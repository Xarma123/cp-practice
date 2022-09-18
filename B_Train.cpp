#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol n, m, k;
    cin >> n >> m >> k;
    string a;
    string b;
    cin >> a >> b;
    string t;
    cin >> t;
    bool ans = false;
    lol dir;
    if (b == "head")
        dir = 1;
    else
        dir = 0;
    lol i;
    for (i = 0; i < t.size(); i++)
    {
        if (t[i] == '0')
        {
            lol knew;
            if (dir)
            {
                if (k == 1)
                {
                    dir = 0;
                    knew = 2;
                }
                else
                {
                    knew = k - 1;
                }
            }
            else
            {
                if (k == n)
                {
                    dir = 1;
                    knew = n - 1;
                }
                else
                {
                    knew = k + 1;
                }
            }
            if (knew == m)
            {
                if (m - 1 > 0 && m - 1 != k)
                    m = m - 1;
                else if (m + 1 < n + 1 && m + 1 != k)
                    m = m + 1;
                else
                {
                    ans = true;
                    break;
                }
            }
            k = knew;
        }
        else
        {
            lol knew;
            if (dir)
            {
                if (k == 1)
                {
                    dir = 0;
                    knew = 2;
                }
                else
                {
                    knew = k - 1;
                }
            }
            else
            {
                if (k == n)
                {
                    dir = 1;
                    knew = n - 1;
                }
                else
                {
                    knew = k + 1;
                }
            }
            k=knew;
            if (k == 1)
                m = n;
            else if (k == n)
                m = 1;
            else if (dir)
                m = n;
            else
                m = 1;
        }
    }
    if (ans)
        cout << "Controller"
             << " " << i + 1;
    else
        cout << "Stowaway";

    return 0;
}