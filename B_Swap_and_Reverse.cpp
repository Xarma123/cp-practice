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
        lol n, k;
        cin >> n >> k;
        string a;
        cin >> a;
        string b = a;
        sort(b.begin(), b.end());
        if (k % 2 == 0)
        {
            cout << b << '\n';
        }
        else
        {
            string x = "", y = "";
            for (lol i = 0; i < a.size(); i++)
            {
                if (i % 2 == 0)
                    x += a[i];
                else
                    y += a[i];
            }
            sort(x.begin(), x.end());
            sort(y.begin(), y.end());
            lol p1 = 0, p2 = 0;
            for (lol i = 0; i < a.size(); i++)
            {
                if (i % 2 == 0)
                {
                    cout << x[p1++];
                }
                else
                    cout << y[p2++];
            }
            cout << '\n';
        }
    }
}