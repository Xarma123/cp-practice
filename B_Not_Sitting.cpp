#include <bits/stdc++.h>
#define lol long long
using namespace std;
lol n, m;
lol dis(lol x, lol y)
{
    return max(x + y, max(abs(x - (m - 1)) + y, max(abs(x - (m - 1)) + abs(y - (n - 1)), x + abs(y - (n - 1)))));
}
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {

        cin >> n >> m;

        multiset<lol> x;
        for (lol i = 0; i < n; i++)
        {
            for (lol j = 0; j < m; j++)
            {
                x.insert(dis(j, i));
            }
        }

        for (auto i = x.begin(); i != x.end(); i++)
        {
            cout << (*i) << " ";
        }
        cout << endl;
    }

    return 0;
}