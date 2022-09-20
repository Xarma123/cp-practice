#include <bits/stdc++.h>
#define lol long long
using namespace std;
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
    bool ans = false;
    for (lol j = 1; j * 1ll * j <= n; j++)
    {

        if (n % j == 0)
        {

            lol i;
            for (i = 0; i < n / j; i++)
            {
                bool f = true;
                lol c = 0;
                for (lol k = i; c < j; k += n / j)
                {
                    k %= n;
                    c++;
                    if (a[k] == 0)
                        f = false;
                }
                if (f)
                    break;
            }
            if (i != n / j && j != 1 && j != 2)
            {

                ans = true;
                break;
            }
            if (n / j != j)
            {
                lol J = n / j;
                for (i = 0; i < n / J; i++)
                {
                    bool f = true;
                    lol c = 0;
                    for (lol k = i; c < J; k += n / J)
                    {
                        k %= n;
                        c++;
                        if (a[k] == 0)
                            f = false;
                    }
                    if (f)
                        break;
                }
                if (i != n / J && J != 1 && J != 2)
                {

                    ans = true;
                    break;
                }
            }
        }
    }
    if (ans)
        cout << "YES";
    else
        cout << "NO";

    return 0;
}