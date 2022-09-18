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
        string a;
        cin >> a;
        for (lol i = 0; i < n; i++)
        {
            if (a[i] == '?')
            {
                if (i != 0)
                {
                    if (a[i - 1] != '?')
                    {
                        if (a[i - 1] == 'R')
                            a[i] = 'B';
                        else
                            a[i] = 'R';
                    }
                }
            }
        }
        for (lol i = n - 1; i >= 0; i--)
        {
            if (a[i] == '?')
            {
                if (i != n - 1)
                {
                    if (a[i + 1] != '?')
                    {
                        if (a[i + 1] == 'R')
                            a[i] = 'B';
                        else
                            a[i] = 'R';
                    }
                }
                else
                {
                    a[i] = 'B';
                }
            }
        }
        cout << a << endl;
    }

    return 0;
}