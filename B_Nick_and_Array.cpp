#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n;
    cin >> n;
    lol a[n];
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    if (n % 2 == 0)
    {
        for (lol i = 0; i < n; i++)
        {
            if (a[i] >= 0)
            {
                a[i] = -a[i] - 1;
            }
            cout << a[i] << " ";
        }
    }
    else
    {

        for (lol i = 0; i < n; i++)
        {
            if (a[i] >= 0)
            {
                a[i] = -a[i] - 1;
            }
        }
        lol mx = -1;
        for (lol i = n - 1; i >= 0; i--)
        {
            if (mx == -1)
                mx = i;
            else if (a[i] < a[mx])
                mx = i;
        }
        if (mx != -1)
        {
            a[mx] = -a[mx] - 1;
            for (lol i = 0; i < n; i++)
            {
                cout << a[i] << " ";
            }
        }
        else
        {
            for (lol i = 0; i < n; i++)
            {
                cout << 0 << " ";
            }
        }
    }
}