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
        lol n;
        cin >> n;
        lol a[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        lol b[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> b[i];
        }

        vector<lol> d, in;
        for (lol i = 0; i < n; i++)
        {
            if (a[i] > b[i])
            {
                lol c = a[i] - b[i];
                while (c--)
                {
                    d.push_back(i + 1);
                }
            }
            else
            {
                lol c = b[i] - a[i];
                while (c--)
                {
                    in.push_back(i + 1);
                }
            }
        }
        if (d.size() == in.size())
        {
            cout << d.size() << '\n';
            for (lol i = 0; i < d.size(); i++)
            {
                cout << d[i] << ' ' << in[i] << '\n';
            }
        }
        else
            cout << -1 << '\n';
    }
}