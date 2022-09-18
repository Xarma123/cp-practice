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
        lol a[n];
        string s;
        for (lol i = 0; i < m; i++)
        {
            s.push_back('B');
        }

        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (lol i = 0; i < n; i++)
        {
            lol x = a[i] - 1;
            lol y = (m + 1) - a[i] - 1;
            if (x > y)
                swap(x, y);
            if (s[x] == 'B')
            {
                s[x] = 'A';
            }
            else
            {
                s[y] = 'A';
            }
        }
        cout << s << endl;
    }

    return 0;
}