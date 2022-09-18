#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol n;
        cin >> n;
        lol x = floorl(log2l(n));
        cout << (long long)powl(2, x) - 1 << endl;
    }

    return 0;
}