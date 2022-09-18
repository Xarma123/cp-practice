#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol n;
    cin >> n;
    lol a[n];
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    bool eat[n];
    eat[n - 1] = true;

    for (lol i = n - 2; i >= 0; i--)
    {
        lol v1 = a[i];
        lol tggle = 0;
        for (lol j = i + 1; j < n; j++)
        {
            if (tggle)
            {
                if (eat[j])
                {
                    v1 += a[j];
                    tggle = 0;
                }
            }
            else
            {
                if (eat[j])
                {
                    tggle = 1;
                }
                else
                {
                    v1 += a[j];
                }
            }
        }
        lol v2 = 0;
        tggle = 1;
        for (lol j = i + 1; j < n; j++)
        {
            if (tggle)
            {
                if (eat[j])
                {
                    v2 += a[j];
                    tggle = 0;
                }
            }
            else
            {
                if (eat[j])
                {
                    tggle = 1;
                }
                else
                {
                    v2 += a[j];
                }
            }
        }
        if (v1 >= v2)
            eat[i] = true;
        else
            eat[i] = false;
    } 

    
    lol v2 = 0, v1 = 0;
    lol tggle = 1;
    for (lol i = 0; i < n; i++)
    {
        if (tggle)
        {
            if (eat[i])
            {
                v2 += a[i];
                tggle = 0;
            }
            else
            {
                v1 += a[i];
            }
        }
        else
        {
            if (eat[i])
            {
                v1 += a[i];
                tggle = 1;
            }
            else
            {
                v2 += a[i];
            }
        }
    }
    cout << v1 << " " << v2 ;

    return 0;
}