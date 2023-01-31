#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol t;
    cin >> t;
    while (t--)
    {
        lol n;
        cin >> n;
        lol a[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        if (n % 2)
        {

            lol x = n / 2 + (n % 2);
            for (lol i = 0; i < n; i++)
            {
                if (a[i] == x)
                {
                    lol v = x - 1;
                    for (lol j = i - 1; j >= 0; j--)
                    {
                        if (a[j] == v)
                            v--;
                    }
                    lol v2 = x + 1;
                    for (lol j = i + 1; j < n; j++)
                    {
                        if (a[j] == v2)
                            v2++;
                    }

                    cout << (n - (1 + 2ll * min(x - v - 1, v2 - x - 1))) / 2 << '\n';
                    break;
                }
            }
        }
        else
        {
            lol x = n / 2;
            for (lol i = 0; i < n; i++)
            {
                if (a[i] == x)
                {
                    lol v = x - 1;
                    for (lol j = i - 1; j >= 0; j--)
                    {
                        if (a[j] == v)
                            v--;
                    }
                    lol v2 = x + 1;
                    for (lol j = i + 1; j < n; j++)
                    {
                        if (a[j] == v2)
                            v2++;
                    }
                    cout << (n - 2ll * min(v2 - x - 1, x - v)) / 2 << '\n'; 
                    
                }
            }
        }
    }

    return 0;
}