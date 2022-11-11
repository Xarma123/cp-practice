#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol a, b;
    cin >> a >> b;
    lol x = -a;
    for (; x <= a; x++)
    {
        lol y2 = (powl(a, 2) - powl(x, 2));

        lol y = sqrtl(y2);
        if (y * 1ll * y == y2 && ((b * 1ll * y) % a == 0) && ((b * 1ll * x) % a == 0))
        {

            lol xk = b * 1ll * y / a;
            lol yk = -b * 1ll * x / a;
            if (!(x == xk || x == 0 || xk == 0 || y == yk || y == 0 || yk == 0))
            {
            cout << "YES" << endl;
            cout << 0 << " " << 0 << endl;
            cout << x << " " << y << endl;
            cout << xk << " " << yk << endl;
            break;}
            xk=-xk;
            yk-yk;
            if (!(x == xk || x == 0 || xk == 0 || y == yk || y == 0 || yk == 0))
            {
            cout << "YES" << endl;
            cout << 0 << " " << 0 << endl;
            cout << x << " " << y << endl;
            cout << xk << " " << yk << endl;
            break;}
        }
        y = -y;
        if (y * 1ll * y == y2 && ((b * 1ll * y) % a == 0) && ((b * 1ll * x) % a == 0))
        {
             lol xk = b * 1ll * y / a;
            lol yk = -b * 1ll * x / a;
            if (!(x == xk || x == 0 || xk == 0 || y == yk || y == 0 || yk == 0))
            {
            cout << "YES" << endl;
            cout << 0 << " " << 0 << endl;
            cout << x << " " << y << endl;
            cout << xk << " " << yk << endl;
            break;}
            xk=-xk;
            yk-yk;
            if (!(x == xk || x == 0 || xk == 0 || y == yk || y == 0 || yk == 0))
            {
            cout << "YES" << endl;
            cout << 0 << " " << 0 << endl;
            cout << x << " " << y << endl;
            cout << xk << " " << yk << endl;
            break;}
        }
    }
    if (x == a + 1)
        cout << "NO";

    return 0;
}