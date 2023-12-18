#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol t;
    cin >> t;
    while (t--)
    {
        lol n, q;
        cin >> n >> q;
        lol d[q];
        for (lol i = 0; i < q; i++)
        {
            cin >> d[i];
        }
        vector<lol> a(d[0] + 1);
        vector<lol> b(n - (d[0] + 1));
        for (lol i = 0; i < a.size(); i++)
        {
            a[i] = i + 1;
            if (i)
                cout << a[i] << " " << a[i - 1] << '\n';
        }
        for (lol i = 0; i < b.size(); i++)
        {
            b[i] = a.back() + i + 1;
            if (i)
                cout << b[i] << " " << b[i - 1] << '\n';
            else
                cout << 2 << " " << b[i] << '\n';
        }
        for (lol i = 0; i < q; i++)
        {
            if (a.size() == d[i] + 1)
                cout << -1 << " " << -1 << " " << -1 << '\n';
            else if (a.size() < d[i] + 1)
            {
                lol j = b.size() - (d[i] + 1 - (long long)a.size());
                cout << b[j] << " ";
                if (j)
                    cout << b[j - 1] << " ";
                else
                    cout << 2 << " ";
                cout << a.back() << '\n';
                stack<lol> x;
                while (b.size() > j)
                {
                    x.push(b.back());
                    b.pop_back();
                }
                while (!x.empty())
                {
                    a.push_back(x.top());
                    x.pop();
                }
            }
            else
            {

                lol j = a.size() - ((long long)a.size() - d[i] - 1);
                cout << a[j] << ' ';
                cout << a[j - 1] << " ";
                if (b.size())
                    cout << b.back() << '\n';
                else
                    cout << 2 << '\n';
                stack<lol> y;
                while (a.size() > j)
                {
                    y.push(a.back());
                    a.pop_back();
                }
                while (!y.empty())
                {
                    b.push_back(y.top());
                    y.pop();
                }
            }
        }
    }

    return 0;
}
