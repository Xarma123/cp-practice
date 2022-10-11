#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n;
    cin >> n;

    while (n--)
    {
        lol a, b;
        cin >> a >> b;
        vector<pair<lol, lol>> pa;
        for (lol i = 2; i * 1ll * i <= a; i++)
        {
            lol c = 0;
            while (a % i == 0)
            {
                a /= i;
                c++;
            }
            if (c)
                pa.push_back({i, c});
        }
        if (a > 1)
            pa.push_back({a, 1});
        vector<pair<lol, lol>> pb;
        for (lol i = 2; i * 1ll * i <= b; i++)
        {
            lol c = 0;
            while (b % i == 0)
            {
                b /= i;
                c++;
            }
            if (c)
                pb.push_back({i, c});
        }
        if (b > 1)
            pb.push_back({b, 1});
        bool ans = true;
        if (pa.size() != pb.size())
            ans = false;
        for (lol i = 0; i < pa.size() && ans; i++)
        {
            if (pa[i].first != pb[i].first)
                ans = false;
            else
            {
                lol x = pa[i].second;
                if (pb[i].second <= 2 * 1ll * x)
                {
                    lol q = 2 * 1ll * x - pb[i].second;
                    if (q % 3 == 0)
                    {
                        q /= 3;
                        if (q > x / 2)
                            ans = false;
                    }
                    else
                        ans = false;
                }
                else
                    ans = false;
            }
        }
        if (ans)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }

    return 0;
}