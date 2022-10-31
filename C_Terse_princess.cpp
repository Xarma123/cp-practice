#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, a, b;
    cin >> n >> a >> b;
    if (n == 1)
    {
        if (a != 0 || b != 0)
            cout << -1;
        else
            cout << 1;
    }
    else if (n == 2)
    {
        if (a)
            cout << -1;
        else if (b == 1)
            cout << "1 2";
        else if (b == 0)
            cout << "1 1";
        else
            cout << -1;
    }
    else
    {
        lol q[n];
        if (b == 0)
        {
            bool f = true;
            q[0] = 2;
            q[1] = 1;
            lol i = 2;

            if (a)
                q[i] = 3, a--, i++;
            else
            {
                for (; i < n; i++)
                {
                    q[i] = q[i - 1];
                    if (q[i] > 50000)
                        f = false;
                }
            }

            for (; i < n && a > 0; i++)
            {
                q[i] = q[i - 1] + 1;
                if (q[i] > 50000)
                    f = false;
                a--;
            }
            if (a || !f)
                cout << -1;
            else
            {
                for (; i < n; i++)
                {
                    q[i] = q[i - 1];
                }

                for (i = 0; i < n; i++)
                {
                    cout << q[i] << " ";
                }
            }
        }
        else
        {
            bool f = true;

            q[0] = 1;
            q[1] = 2;
            b--;
            lol i = 2;

            lol s = 3;
            for (; b > 0 && i < n; i++)
            {
                q[i] = s + 1;
                if (q[i] > 50000)
                    f = false;
                s += q[i];
                b--;
            }
            for (; a > 0 && i < n; i++)
            {
                q[i] = q[i - 1] + 1;
                if (q[i] > 50000)
                    f = false;
                s += q[i];
                a--;
            }

            for (; i < n; i++)
            {
                q[i] = q[i - 1];
                if (q[i] > 50000)
                    f = false;
            }
            if (f)
            {
                for (i = 0; i < n; i++)
                {
                    cout << q[i] << " ";
                }
            }
            else
                cout << -1;
        }
    }
    return 0;
}