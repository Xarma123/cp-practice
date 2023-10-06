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
        lol n, m;
        cin >> n >> m;
        set<lol> used;
        vector<lol> match;
        for (lol i = 0; i < m; i++)
        {
            lol x, y;
            cin >> x >> y;
            if (used.count(x) || used.count(y))
                continue;
            used.insert(x);
            used.insert(y);
            match.push_back(i + 1);
        }
        if (match.size() >= n)
        {
            cout << "Matching\n";
            for (lol i = 0; i < n; i++)
            {
                cout << match[i] << " ";
            }
            cout << '\n';
        }
        else
        {
            cout << "IndSet\n";
            lol c = 0;
            for (lol i = 1; i <= 3ll * n && c < n; i++)
            {
                if (!used.count(i))
                {
                    c++;
                    cout << i << " ";
                }
            }
            cout << '\n';
        }
    }
}