#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("output.txt", "a+", stdout);
    for (lol n = 1; n < 10000; n++)
    {

        vector<lol> v;
        for (lol i = 1; i <= n; i++)
        {
            v.push_back(i);
        }
        bool f = true;
        while (v.size() > 1)
        {
            vector<lol> x;
            if (f)
            {
                for (lol i = 1; i < v.size(); i += 2)
                {
                    x.push_back(v[i]);
                }
                v.clear();
                for (auto e : x)
                    v.push_back(e);
                f = false;
            }
            else
            {
                for (lol i = v.size() - 2; i >= 0; i -= 2)
                {
                    x.push_back(v[i]);
                }
                reverse(x.begin(), x.end());
                v.clear();
                for (auto e : x)
                    v.push_back(e);
                f = true;
            }
        }
        cout << "(" << n << "," << v[0] << ")" << endl;
    }

    return 0;
}