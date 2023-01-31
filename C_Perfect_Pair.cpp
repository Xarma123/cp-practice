#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol x, y, m;
    cin >> x >> y >> m;
    if (x > y)
        swap(x, y);
    if (y >= m)
        cout << 0;
    else if (y <= 0)
        cout << -1;
    else
    {
        lol k = ceill((-x) / (long double)y);
        x += k * 1ll * y;
        if (x > y)
            swap(x, y);
        lol c = 0;
        while (y < m)
        {
            x += y;
            if (x > y)
                swap(x, y);
            c++;
        }
        cout << c + k;
    }

    return 0;
}