#include <bits/stdc++.h>
#define lol long long
using namespace std;
lol x, y;
lol in, seg;
lol n;
bool val(lol x1, lol y1)
{

    bool f = (powl(x - x1, 2) + powl(y - y1, 2) <= (((4 * 1ll * n * 1ll * n - 4 * 1ll * n) + 1) / (long double)4));

    return f;
}
void check(lol x1, lol y1)
{
    if (val(x1, y1) &&
        val(x1 + 1, y1) &&
        val(x1, y1 + 1) &&
        val(x1 + 1, y1 + 1))
    {
        in++;
        return;
    }
    if (val(x1, y1) ||
        val(x1 + 1, y1) ||
        val(x1, y1 + 1) ||
        val(x1 + 1, y1 + 1))
        seg++;
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    bool f = false;
    while (cin >> n)
    {
        in = 0;
        seg = 0;
        if (f)
            cout << endl;
        x = n;
        y = n;

        for (lol i = 0; i < 2 * 1ll * n; i++)
        {
            for (lol j = 0; j < 2 * 1ll * n; j++)
            {
                check(i, j);
            }
        }
        f = true;
        cout << "In the case n = " << n << ", " << seg << " cells contain segments of the circle." << endl;
        cout << "There are " << in << " cells completely contained in the circle." << endl;
    }

    return 0;
}