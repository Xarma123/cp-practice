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
        lol a[n - 1];
        for (lol i = 0; i < n - 1; i++)
        {
            cin >> a[i];
        }
        vector<lol> b(n - 1);
        for (lol i = 0; i < n - 1; i++)
        {
            if (i == 0)
                b[i] = a[i];
            else
                b[i] = a[i] - a[i - 1];
        }
        sort(b.begin(), b.end());
        bool ans = true;
        lol c = 0;
        for (lol i = 0; i < n - 1 && ans; i++)
        {
            if (b[i] > n)
            {
                if (c > 0)
                {
                    ans = false;
                }
                else
                    c++;
                if (b[i] > n + n - 1)
                {
                    ans = false;
                }
            }
            if (b[i] < 1)
            {
                ans = false;
            }
        }

        for (lol i = 0; i < n - 1; i++)
        {
            if (b[i] != i + 1)
            {
                b.push_back(i + 1);

                break;
            }
        }
        if (b.size() == n - 1)
            b.push_back(n);
        for (lol i = 0; i < n - 1; i++)
        {
            if (b[i] > n)
            {
                b[i] -= b.back();
                break;
            }
            if (i)
            {
                if (b[i] == b[i - 1])
                {
                    b[i] -= b.back();
                    break;
                }
            }
        }
        sort(b.begin(), b.end());
        for (lol i = 0; i < n; i++)
        {
            if (b[i] != i + 1)
            {
                ans = false;
                break;
            }
        }
        if (ans)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}