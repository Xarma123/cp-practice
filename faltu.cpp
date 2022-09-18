#include <bits/stdc++.h>
#define lol long long
using namespace std;

int main()
{

    lol k;
    cin >> k;

    lol c = 0;
    for (lol i = 0; i < 1e5; i++)
    {
        lol x = (rand() % (k - 1) + 1);
        lol y = (rand() % (k - 1) + 1);
        if (__gcd(x, y) == 1)
            c++;
    }
    long double sum = 0;
    for (lol i = 0; i < 1e5; i++)
    {
        sum += 1 / (long double)((i + 1) * (long double)(i + 1));
    }
    long double p = 1e5 / (long double)c;
    cout << p << " " << sum;

    return 0;
}