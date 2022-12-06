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
    lol c = 1;
    while (t--)
    {
        lol n, y;
        cin >> n >> y;
        vector<vector<lol>> ci;
        while (n--)
        {
            lol a, b, r;
            cin >> a >> b >> r;
            ci.push_back({a, b, r});
        }
        cout << "Case " << c << ":" << endl;
        while (y--)
        {
            lol a, b;
            cin >> a >> b;
            bool f = false;
            for (auto e : ci)
            {
                if ((e[0] - a) * (e[0] - a) + (e[1] - b) * (e[1] - b) <= e[2] * e[2])
                    f = true;
            }
            if (f)
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        } 
        c++;
    }

    return 0;
}