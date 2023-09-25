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
        lol st, in, e;
        cin >> st >> in >> e;
        st += e;
        if (st <= in)
            cout << 0 << '\n';
        else
        {
            lol k = (st - in - 1) / 2;
            k = min(k, e);
            cout << k + 1 << '\n';
        }
    }
}