#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol t;
    cin >> t;
    while (t--)
    {
        lol b, c, h;
        cin >> b >> c >> h;
        b--;
        cout << min(b, c + h) * 2ll + 1 << '\n';
    }
}