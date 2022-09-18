#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol n, m, rb, cb, rd, cd;
        cin >> n >> m >> rb >> cb >> rd >> cd;
        lol r;
        if (rd < rb)
        {
            r = 2 * (n - rb) + (rb - rd);
        }
        else
            r = (rd - rb);
        lol c;
        if (cd < cb)
        {
            c = 2 * (m - cb) + (cb - cd);
        }
        else
            c = (cd - cb);
        cout<<min(r,c)<<endl;
    }

    return 0;
}