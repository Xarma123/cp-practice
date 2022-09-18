#include <bits/stdc++.h>
#define lol long long
using namespace std;
lol n;
bool check6(lol no)
{
    return pow(no, 6) <= n;
}
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {

        cin >> n;
        lol s = 1;
        lol e = 1e18;
        while (s != e - 1)
        {
            lol m = (s + e) / 2;
            if (check6(m))
                s = m;
            else
                e = m;
        }

        cout << floor(sqrt(n)) + floor(cbrt(n)) -s<< endl;
    }

    return 0;
}