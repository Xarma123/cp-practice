#include <iostream>
#include <stack>
using namespace std;

int main()
{
    lol n;
    cin >> n;
    lol a[n], b[n];
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
        b[n - 1 - i] = a[i];
    }
    lol ans[n] = {0};
    lol max = 0;
    stack<lol> as, as2;
    for (lol i = 0; i < n; i++)
    {
        if (i == 0)
        {
            as.push(i);
            ans[i] += 1 * a[i];
        }
        else
        {
            while (!as.empty() && a[i] <= a[as.top()])
            {
                as.pop();
            }

            if (!as.empty())
            {
                ans[i] += a[i] * (i - as.top());
                as.push(i);
            }

            else
            {
                ans[i] += a[i] * (i + 1);
                as.push(i);
            }
        }
        if (i == 0)
        {
            as2.push(i);
            ans[n - 1 - i] += 1 * b[i];
        }
        else
        {
            while (!as2.empty() && b[i] <= b[as2.top()])
            {
                as2.pop();
            }

            if (!as2.empty())
            {
                ans[n - 1 - i] += b[i] * (i - as2.top());
                as2.push(i);
            }

            else
            {
                ans[n - 1 - i] += b[i] * (i + 1);
                as2.push(i);
            }
        }

        ans[i] -= a[i];
        if (ans[i] >= max)
            max = ans[i];
    }
    cout << max;
}