#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int a[500];
    int i;
    
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;

    int x = 1826;
    for (i = n - 1; i >= 0; i--)
    {
        a[i + 1] = a[i];
    }
    a[0] = x;
    n++;

    x = 1826;
    a[n] = x;
    n++;

    x = 4;
    int ele = 1826;
    for (i = n - 1; i >= x; i--)
    {
        a[i + 1] = a[i];
    }
    a[x] = ele;
    n++;

    int idx = -1;
    x = 3;
    ele = 1826;

    for (i = 0; i < n; i++)
    {
        if (a[i] == x)
        {
            idx = i;
            break;
        }
    }

    if (idx == -1)
    {
        cout << "Reference element absent" << endl;
    }
    else
    {
        for (i = n - 1; i > idx; i--)
        {
            a[i + 1] = a[i];
        }
        a[idx + 1] = ele;
        n++;
    }

    idx = -1, x = 2;
    for (i = 0; i < n; i++)
    {
        if (a[i] == x)
        {
            idx = i;
            break;
        }
    }

    if (idx == -1)
    {
        cout << "element absent" << endl;
    }
    else
    {
        for (i = idx; i < n - 1; i++)
        {
            a[i] = a[i + 1];
        }
        n--;
    }

    for (i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}
