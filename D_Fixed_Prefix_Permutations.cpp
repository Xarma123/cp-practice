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
        lol n, m;
        cin >> n >> m;
        lol a[n][m];
        set<string> x;
        for (lol i = 0; i < n; i++)
        {
            string q = "";
            x.insert(q);
            for (lol j = 0; j < m; j++)
            {
                q.push_back('a');
                cin >> a[i][j];
            }
            for (lol j = 0; j < m; j++)
            {
                q[a[i][j] - 1] = char(j + '0');
            }
            while ((long long)q.size() > 0ll)
            {
                x.insert(q);
                q.pop_back();
            }
        }
        for (lol i = 0; i < n; i++)
        {
            string q = "";
            lol j = 0;
            while (x.count(q) && j < m)
            {
                q.push_back(char(a[i][j] - 1 + '0'));
                j++;
            }
            if (x.count(q))
                cout << (long long)q.size() << " ";
            else
                cout << (long long)q.size() - 1 << " ";
        }
        cout << '\n';
    }

    return 0;
}