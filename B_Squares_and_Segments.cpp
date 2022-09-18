#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol n;
    cin >> n;
    if (n == 1)
        cout << 2;
    else
    {
        lol s = ceil(sqrtl(n));
        if(n/s==0)
        {
            cout<<1+n%s;
        }
        else
        {
            cout<<ceill(n/(long double)s)+s;
        }
    }

    return 0;
}