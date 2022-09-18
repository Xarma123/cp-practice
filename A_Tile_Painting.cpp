#include <bits/stdc++.h>
#define lol long long
using namespace std;
bool isPrime(lol n)
{
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;

    for (lol i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;

    return true;
}
int main()
{
    lol n;
    cin >> n;
    if (isPrime(n))
        cout << n;
    else
    {
        lol p;

        lol c = 0;
        lol i;
        for (i = 1; i * i < n; i++)
        {
            if (n % i == 0)
            {
                if (isPrime(i))
                {
                    p = i;
                    c++;
                }
            }
            if (c == 2)
                break;
        }
        if (c != 2)
        {
            if (i - (n / i) == 1)
            {
                i--;
            }
            for (; i >= 1; i--)
            {
                if (n % i == 0)
                {
                    if (isPrime(n / i))
                    {
                        p = n / i;
                        c++;
                    }
                }
                if (c == 2)
                    break;
            }
        }
        if (c==1)
        cout<<p;
        else
        cout<<1;
    }

    return 0;
}