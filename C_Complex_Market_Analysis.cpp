#include <bits/stdc++.h>
#define lol long long
using namespace std;
lol binpower(lol base, lol e, lol mod)
{
    lol result = 1;
    base %= mod;
    while (e)
    {
        if (e & 1)
            result = (long long)result * base % mod;
        base = (long long)base * base % mod;
        e >>= 1;
    }
    return result;
}
bool check_composite(lol n, lol a, lol d, lol s)
{
    lol x = binpower(a, d, n);
    if (x == 1 || x == n - 1)
        return false;
    for (lol r = 1; r < s; r++)
    {
        x = (long long)x * x % n;
        if (x == n - 1)
            return false;
    }
    return true;
};
bool MillerRabin(lol n)
{ // returns true if n is prime, else returns false.
    if (n < 2)
        return false;

    lol r = 0;
    lol d = n - 1;
    while ((d & 1) == 0)
    {
        d >>= 1;
        r++;
    }

    for (lol a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37})
    {
        if (n == a)
            return true;
        if (check_composite(n, a, d, r))
            return false;
    }
    return true;
}
bool isPrime(lol x)
{
    for (lol d = 2; d * d <= x; d++)
    {
        if (x % d == 0)
            return false;
    }
    return true;
}
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol n, e;
        cin >> n >> e;
        lol a[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        lol ans = 0;
        for (lol i = 0; i < n ; i++)
        {
            if (MillerRabin(a[i]))
            {  
                lol k = 1;
                lol one_back = 0;
                while (1)
                {
                    if (i - e * k >= 0)
                    {
                        if (a[i - e * k] == 1)
                        {
                            one_back++;
                            k++;
                        }
                        else
                            break;
                    }
                    else
                        break;
                }
                k = 1;
                lol one_f = 0;
                while (1)
                {
                    if (i + e * k < n)
                    {
                        if (a[i + e * k] == 1)
                        {
                            one_f++;
                            k++;
                        }
                        else
                            break;
                    }
                    else
                        break;
                }
                ans += one_back;
                ans += one_f;
                ans += one_f * one_back;

            } 
        }
           
        cout << ans << endl;
    }

    return 0;
}