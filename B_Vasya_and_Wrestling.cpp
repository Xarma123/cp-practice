#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol n;
    cin >> n;
    queue<lol> x1, x2;
    lol s = 0;
    lol last;
    for (lol i = 0; i < n; i++)
    {
        lol t;
        cin >> t;
        if (i == n - 1)
        {
            if (t > 0)
                last = 1;
            else
                last = 0;
        }
        s += t;
        if (t > 0)
            x1.push(t);
        else
            x2.push(-t);
    }
    if (s != 0)
    {
        if (s > 0)
            cout << "first";
        else
            cout << "second";
    }
    else
    {
        lol ans = 3;
        while ((!x1.empty()) && (!x2.empty()))
        {
            if (x1.front() > x2.front())
            {
                ans = 1;
                break;
            }
            else if (x1.front() < x2.front())
            {
                ans = 0;
                break;
            }
            else
            {
                x1.pop();
                x2.pop();
            }
        }
        if (ans == 1)
        {
            cout << "first";
        }
        else if (ans == 0)
            cout << "second";
        else
        {
            if (last)
            {
                cout << "first";
            }
            else
                cout << "second";
        }
    }

    return 0;
}