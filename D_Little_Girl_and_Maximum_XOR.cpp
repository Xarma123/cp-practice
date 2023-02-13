#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol l, r;
    cin >> l >> r;
    lol i;
    for (i = 63; i >= 0; i--)
    {
        if (((1ll << i) & r) && (!((1ll << i) & l)))
            break;
    }
    i++;
    cout << (1ll << i) - 1;

    return 0;
}