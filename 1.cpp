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
        lol a, b;
        cin >> a >> b;
        lol ar[n];
        for (lol i = 0; i < n; i++)
        {
            ar[i] = i + 1;
        }
        if (n <= 2)
        {
            if (a == 0 && b == 0)
            {
                for (lol i = 0; i < n; i++)
                {
                    cout << ar[i] << " ";
                }
                cout << endl;
                continue;
            }
            else
                cout << -1 << endl;
        }
        else
        {
            if (a == b)
            {
                lol up = 0, down = 0;
                if (up == a && down == b)
                {
                    for (lol i = 0; i < n; i++)
                    {
                        cout << ar[i] << " ";
                    }
                    cout << endl;
                    continue;
                }
                for (lol i = 1; i < n; i = i + 2)
                {
                    if (i + 1 < n)
                    {
                        swap(ar[i], ar[i + 1]);
                        up++;
                        if (i != n - 2)
                            down++;
                        if (up == a && down == b)
                            break;
                    }
                }
                if (up == a && down == b)
                {
                    for (lol i = 0; i < n; i++)
                    {
                        cout << ar[i] << " ";
                    }
                    cout << endl;
                }
                else
                {
                    cout << -1 << endl;
                }
            }
            else if (a > b)
            {
                lol up = 0, down = 0;

                for (lol i = n - 1; i >= 0; i = i - 2)
                {
                    if (i - 1 >= 0)
                    {
                        swap(ar[i], ar[i - 1]);
                        if (i != 1)
                            up++;
                        if (i != n - 1)
                            down++;
                        if (up == a && down == b)
                            break;
                    }
                }
                if (up == a && down == b)
                {
                    for (lol i = 0; i < n; i++)
                    {
                        cout << ar[i] << " ";
                    }
                    cout << endl;
                }
                else
                {
                    cout << -1 << endl;
                }
            }
            else
            {
                lol up = 0, down = 0;

                if (up == a && down == b)
                {
                    for (lol i = 0; i < n; i++)
                    {
                        cout << ar[i] << " ";
                    }
                    cout << endl;
                    continue;
                }

                for (lol i = 0; i < n; i = i + 2)
                {
                    if (i + 1 < n)
                    {
                        swap(ar[i], ar[i + 1]);
                        if (i != 0)
                            up++;
                        if (i != n - 1)
                            down++;
                        if (up == a && down == b)
                            break;
                    }
                }
                if (up == a && down == b)
                {
                    for (lol i = 0; i < n; i++)
                    {
                        cout << ar[i] << " ";
                    }
                    cout << endl;
                }
                else
                {
                    cout << -1 << endl;
                }
            }
        }
    }
    return 0;
}