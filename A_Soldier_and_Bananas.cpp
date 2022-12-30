#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol k, n, w;
    cin >> k >> n >> w;
    cout << max((k * 1ll * w * 1ll * (w + 1) / 2ll) - n, 0ll);

    return 0;
}