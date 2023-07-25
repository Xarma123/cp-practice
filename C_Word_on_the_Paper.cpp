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

        string a[8];
        for (lol i = 0; i < 8; i++)
        {
            cin >> a[i];
        }
        string ans = "";
        for (lol j = 0; j < 8; j++)
        {

            for (lol i = 0; i < 8; i++)
            {
                if (a[i][j] != '.')
                    ans.push_back(a[i][j]);
            }
        }
        cout << ans << '\n';
    }
}