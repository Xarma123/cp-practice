#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol t;
    cin >> t;
    while (t--)
    {
        lol w, d, h;
        cin >> w >> d >> h;
        lol a, b, f, g;
        cin >> a >> b >> f >> g;
        cout << min(a + abs(f) + abs(g - b), min(w - a + abs(w - f) + abs(g - b), min(b + abs(f - a) + abs(g), d - b + abs(f - a) + abs(g - d)))) + h << endl;
    }

    return 0;
}