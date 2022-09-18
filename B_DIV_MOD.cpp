#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol l, r, a;
        cin >> l >> r >> a;
        lol v = r % a + r / a;
        r -= r % a;
        r--;
        if (r >= l)
            v = max(v, (r % a + r / a));
        cout << v << endl;
    }

    return 0;
}