#include <bits/stdc++.h>
#define lol long long
using namespace std;

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol a1, a2, a3, a4, a5, a6;
    cin >> a1 >> a2 >> a3 >> a4 >> a5 >> a6;

    cout << fixed<< (long long)powl((a1 + a2 + a3), 2) - (a1 * 1ll * a1) - (a3 * 1ll * a3) - (a5 * 1ll * a5);
    return 0;
}