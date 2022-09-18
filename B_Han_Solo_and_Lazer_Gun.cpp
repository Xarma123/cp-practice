#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, x, y;
    cin >> n >> x >> y;
    set<long double> count;
    bool f = false;
    while (n--)
    {
        lol x1, y1;
        cin >> x1 >> y1;
        x1 -= x;
        y1 -= y;
        if (x1 == 0)
            f = true;
        else
            count.insert(y1 / (long double)x1);
    }
    cout << count.size() + f;

    return 0;
}