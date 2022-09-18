#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol px, py;
        cin >> px >> py;
        string s;
        cin >> s;
        char a;
        if (px >= 0)
        {
            a = 'R';
        }
        else
        {
            px = -px;
            a = 'L';
        }
        char b;
        if (py >= 0)
        {
            b = 'U';
        }
        else
        {
            py = -py;
            b = 'D';
        }
        lol x = 0, y = 0;
        for (lol i = 0; i < s.size(); i++)
        {
            if (s[i] == a)
                x++;
            else if (s[i] == b)
                y++;
        }
        if (x >= px && y >= py)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}