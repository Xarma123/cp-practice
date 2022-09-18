#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string a[4];
    for (lol i = 0; i < 4; i++)
    {
        cin >> a[i];
    }

    for (lol i = 0; i < 3; i++)
    {
        for (lol j = 0; j < 3; j++)
        {
            lol hash = 0;
            if (a[i][j] == '#')
                hash++;
            if (a[i][j + 1] == '#')
                hash++;
            if (a[i + 1][j] == '#')
                hash++;
            if (a[i + 1][j + 1] == '#')
                hash++;
            if (hash != 2)
            {
                cout << "YES";
                return 0;
            }
        }
    }

    cout << "NO";

    return 0;
}