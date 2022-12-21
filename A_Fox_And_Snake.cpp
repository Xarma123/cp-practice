#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, m;
    cin >> n >> m;
    bool f = true;
    for (lol i = 0; i < n; i++)
    {
        if (i % 2 == 0)
        {
            for (lol j = 0; j < m; j++)
            {
                cout << '#';
            }
            cout << endl;
        }
        else
        {
            if (!f)
            {
                cout << '#';
            }
            for (lol j = 0; j < m - 1; j++)
            {
                cout << '.';
            }
            if (f)
            {
                cout << '#';
            }
            if (f)
                f = false;
            else
                f = true;
            cout << endl;
        }
    }

    return 0;
}