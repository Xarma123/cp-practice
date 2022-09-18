#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, k;
    cin >> n >> k;
    lol e = 1e10;
    lol s = 0;
    while (s != e - 1)
    {
        lol m = (s + e) / 2;
        lol c = 0;
        lol M = m;
        while (m)
        {
            c += m;
            m /= k;
        }
        if (c >= n)
            e = M;
        else
            s = M;
    }
    cout << e;

    return 0;
}