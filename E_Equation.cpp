#include <bits/stdc++.h>
#define lol long double
using namespace std;
long double c;
bool check(lol x)
{
    return pow(x, 2) + sqrt(x) >= c;
}

int main()
{

    cin >> c;
    lol s = 0;
    lol e = 1e18;

    for (lol i = 0; i < 400; i++)
    {
        lol m = (s + e) / 2;
        if (check(m))
            e = m;
        else
            s = m;
    }
    cout << setprecision(16) << e;

    return 0;
}