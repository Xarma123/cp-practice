#include <bits/stdc++.h>
using namespace std;
#define lol long long
bool cmp(vector<lol> a, vector<lol> b)
{
    for (lol i = 0; i < a.size(); i++)
    {
        if (a[i] > b[i])
            return true;
        else if (b[i] > a[i])
            return false;
    }
    return false;
}
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol n;
        cin >> n;
        lol p[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> p[i];
        }
        if (n == 1)
        {
            cout << p[0] << '\n';
        }
        else
        {
            lol mx = 0;
            lol j;
            for (lol i = 1; i < n; i++)
            {
                if (mx < p[i])
                {
                    mx = p[i];
                    j = i;
                }
            }
            vector<vector<lol>> all;
            for (lol i = 0; i < j; i++)
            {
                vector<lol> a;
                for (lol k = j; k < n; k++)
                {
                    a.push_back(p[k]);
                }
                // i to j-1
                for (lol k = j - 1; k >= i; k--)
                {
                    a.push_back(p[k]);
                }
                // 0 to i-1
                for (lol k = 0; k < i ; k++)
                    a.push_back(p[k]);
                all.push_back(a);
            }
            if (j == n - 1)
            {
                vector<lol> a;
                a.push_back(p[n - 1]);
                for (lol i = 0; i < n - 1; i++)
                {
                    a.push_back(p[i]);
                }
                all.push_back(a);
            }
            sort(all.begin(), all.end(), cmp);
            for (auto e : all[0])
                cout << e << " ";
            cout << '\n';
        }
    }
}