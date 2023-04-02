#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string a[8];
    for (lol i = 7; i >= 0; i--)
    {
        cin >> a[i];
        for (lol j = 0; j < 8; j++)
        {
            if (a[i][j] == '*')
            {
                cout << char('a' + j);
                cout << char('1' + i);
            }
        }
    }

    return 0;
}