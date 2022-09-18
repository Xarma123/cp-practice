#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol n;
    cin >> n;
    lol a[n];
    lol ans = 0;
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    lol l = 0;
    for (lol i = 0; i < n; i++)
    {
        if (a[i] == 0)
        {
            l = 0;
            ans++;
        }
        else if (a[i] == 1)
        {
            if (l == 1)
            {
                ans++;
                l = 0;
            }
            else
                l = 1;
        }
        else if (a[i] == 2)
        {
            if (l == 2)
            {
                ans++;
                l = 0;
            }
            else
                l = 2;
        }
        else
        {
            if (l == 1 || l == 2)
            {
                while (a[i] == 3)
                {
                    if (l == 1)
                        l = 2;
                    else
                        l = 1;
                    i++;
                    if (i == n)
                        break;
                }
                i--;
            }
            else
            {
                l = 0;
            }
        }
    }
    cout<<ans;

    return 0;
}