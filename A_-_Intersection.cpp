#include <bits/stdc++.h>
#define lol long long
using namespace std;

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol l1, r1, l2, r2;
    cin >> l1 >> r1 >> l2 >> r2;
    if (r1 < l2 || l1 > r2)
        cout << 0;
    else if (l1 >= l2 && r1 <= r2)
    {
        cout << r1 - l1;
    }
    else
    {
        cout << min(r1, r2) - max(l1, l2);
    }

    return 0;
}