#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol n, k;
    cin >> n >> k;
    lol a[n];
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n);
    for (lol i = n / 2; i < n; i++)
    {
        if (i + 1 == n)
        {
            a[n / 2] += k / (i - n / 2 + 1);
        }
        else
        {
            if (k / (i - n / 2 + 1) + a[n / 2] <= a[i + 1])
            {
                a[n / 2] += k / (i - n / 2 + 1);
                break;
            }
            else
            {
                k -= (a[i + 1] - a[n / 2]) * ((i - n / 2 + 1));
                a[n / 2] = a[i + 1];
            }
        }
    } 
    cout<<a[(n/2)];

    return 0;
}