#include <bits/stdc++.h>
#define lol long long
using namespace std;
lol S, W, C, K, M;
bool check()
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> S >> W >> C >> K >> M;
    lol s = -1, e = 1e18;
    while (s != e - 1)
    {
        lol m = (s + e) / 2;
        if (check(m))
            e = m;
        else
            s = m;
    }

    return 0;
}