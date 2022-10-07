#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol a, b;
    lol c = 1;
    while (1)
    {
        cin >> a >> b;
        if (a == b && a == 0)
            break;
        cout << "Case " << c << ": ";
        if (a == 0 || b == 0)
            cout << 0 << endl;
        else
            cout << a * 1ll * b * 1ll * (a - 1) * 1ll * (b - 1) / 4 << endl;
        c++;
    }

    return 0;
}