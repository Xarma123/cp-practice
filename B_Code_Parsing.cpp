#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s;
    cin >> s;
    lol x = 0, y = 0;
    for (auto c : s)
    {
        if (c == 'x')
            x++;
        else
            y++;
    }
    if (x <= y)
    {
        y -= x;
        for (lol i = 0; i < y; i++)
        {
            cout << 'y';
        }
    }
    else
    {
        x -= y;
        for (lol i = 0; i < x; i++)
        {
            cout << 'x';
        }
    }

    return 0;
}