#include <bits/stdc++.h>
#define lol long long
using namespace std;

double myPow(double x, lol n)
{
    if (n == 0)
        return 1;
    double ans = 1;
    while (n > 0)
    {
        if (n % 2 != 0)
        {
            ans = ans * x;
        }
        x = x * x;
        n >>= 1;
    }
    if (n < 0)
    {
        unsigned lol n1 = abs(n);

    }
    return ans;
}

int main()
{
    cout << myPow(1, -2) << endl;
}