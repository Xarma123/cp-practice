#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol n, m;
    cin >> n >> m;
    if (m >= n - 1 && m <= 2 * (n + 1))
    {
        string a = "";
        lol x = n;
        while (x--)
        {
            a += "0";
        }
        m -= n - 1;
        if (m)
        {
            if (m == 1)
            {
                a.insert(0, "1");
                m--;
            }
            else
            {
                a.insert(0, "11");
                m -= 2;
            }
        }

        for (lol i = 3; i < a.size(); i++)
        {
            if (m)
            {
                a.insert(i, "11");
                i += 2;
                m--;
            }
            else
            {
                a.insert(i, "1");
                i++;
            }
        }

        if (m)
        {
            a.append("1");
            m--;
            if (m)
            {
                a.append("1");
                m--;
            }
        }
        cout << a;
    }
    else
        cout << -1;

    return 0;
}