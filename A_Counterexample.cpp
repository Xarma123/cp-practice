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
    if (l % 2 == 0)
    {
        if (r - l + 1 >= 3)
        {
            cout << l << " " << l + 1 << " " << l + 2;
        }
        else
            cout << -1;
    }
    else
    {
        if (r - l + 1 >= 4)
        {
            cout << l + 1 << " " << l + 2 << " " << l + 3;
        }
        else
            cout << -1;
    }

    return 0;
}