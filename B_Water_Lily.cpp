#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol h, l;
    cin >> h >> l;
    long double ans = (l * 1ll * l - h * 1ll * h) / (long double)(2ll * h);
    cout << fixed << setprecision(13) << ans;
}