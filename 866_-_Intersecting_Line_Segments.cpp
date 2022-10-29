#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol t;
    cin >> t;
    while (t--)
    {
        lol q;
        cin >> q;
        vector<vector<lol>> a;
        for (lol i = 0; i < q; i++)
        {
            lol a, b, c, d;
            cin >> a >> b >> c >> d;
            a.push_back({a, b, c, d});
        }
        for (auto e : a)
        {
            
        }

        if (t)
            cout << endl;
    }

    return 0;
}