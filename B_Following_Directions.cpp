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
        lol n;
        cin >> n;
        string s;
        cin >> s;
        lol x = 0, y = 0;
        bool ans = false;
        for (auto c : s)
        {
            if (c == 'U')
                y++;
            else if (c == 'D')
                y--;
            else if (c == 'L')
                x--;
            else
                x++;
            if (x == 1 && y == 1)
                ans = true;
        }
        if (ans)
            cout << "YES" << '\n';
        else
            cout << "NO" << '\n';
    }

    return 0;
}