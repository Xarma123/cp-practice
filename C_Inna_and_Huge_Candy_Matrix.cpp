#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, m, x, y, z, p;
    cin >> n >> m >> x >> y >> z >> p;
    lol N = n, M = m;
    z = z * 3ll;
    x %= 4;
    y %= 2;
    z %= 4;
    lol X = x, Y = y, Z = z;
    for (lol i = 0; i < p; i++)
    {
        lol r, c;
        cin >> r >> c;
        x = X, y = Y, z = Z;
        n = N, m = M;
        while (x--)
        {
            lol nr = c;
            lol nc = n - r + 1;
            swap(n, m);
            r = nr;
            c = nc;
        }

        while (y--)
        {
            c = m - c + 1;
        }

        while (z--)
        {
            lol nr = c;
            lol nc = n - r + 1;
            swap(n, m);
            r = nr;
            c = nc;
        }
        cout << r << " " << c << endl;
    }

    return 0;
}