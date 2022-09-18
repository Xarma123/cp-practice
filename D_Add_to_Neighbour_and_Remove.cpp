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
        lol a[n];
        lol sum = 0;
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
            sum += a[i];
        }
        lol i;
        for (i = n; i >= 1; i--)
        {
            if (sum % i == 0)
            {

                lol s = sum / i;
                lol sx = 0;
                lol j;
                for (j = 0; j < n; j++)
                {
                    sx += a[j];
                    if (sx == s)
                        sx = 0;
                    if (sx > s)
                        break;
                }
                if (j == n)
                {
                    cout << n - i << endl;
                    break;
                }
            }
        }
    }
    return 0;
}