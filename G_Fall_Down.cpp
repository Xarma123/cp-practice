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
        string a[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (lol j = 0; j < m; j++)
        {
            stack<char> x;
            for (lol i = 0; i < n; i++)
            {
                if (a[i][j] != '.')
                {
                    if (a[i][j] == 'o')
                    {
                        lol k = i - 1;
                        while (!x.empty())
                        {
                            a[k][j] = x.top();
                            x.pop();
                            k--;
                        }
                    }
                    else
                    {
                        x.push(a[i][j]);
                        a[i][j] = '.';
                    }
                }
            }
            lol i = n - 1;
            while (!x.empty())
            {
                a[i][j] = x.top();
                x.pop();
                i--;
            }
        }
        for (lol i = 0; i < n; i++)
        {
            cout << a[i] << endl;
        }
    }

    return 0;
}