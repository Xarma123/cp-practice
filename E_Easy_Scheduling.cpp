#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol h, p;
        cin >> h >> p;
        lol a = (long long)ceil(log2l(p));
        if (a >= h)
        {
            cout << h << endl;
        }
        else
        {
            lol b = (long long)powl(2, a) - 1;
            lol c = (long long)powl(2, h) - 1;
            lol n = ceil((c - b) * 1.0 / p) + a;
            cout << n << endl;
        }
    }

    return 0;
}