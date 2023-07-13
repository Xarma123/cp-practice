#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        string s[3];
        cin >> s[0] >> s[1] >> s[2];
        char c = 'D';
        for (lol i = 0; i < 3 && c == 'D'; i++)
        {
            if (s[i] == "XXX")
                c = 'X';
            else if (s[i] == "OOO")
                c = 'O';
            else if (s[i] == "+++")
                c = '+';
        }
        for (lol j = 0; j < 3 && c == 'D'; j++)
        {
            lol i = 1;
            for (; i < 3; i++)
            {
                if (s[i][j] != s[i - 1][j])
                    break;
            }
            if (i >= 3 && s[i - 1][j] != '.')
            {
                c = s[i - 1][j];
            }
        }
        lol i, j;
        for (i = 1, j = 1; i < 3 && j < 3 && c == 'D'; i++, j++)
        {
            if (s[i][j] != s[i - 1][j - 1])
                break;
        }
        if (i >= 3&&s[0][0]!='.')
        {
            c = s[0][0];
        }
        for (i = 1, j = 1; i < 3 && j >= 0 && c == 'D'; i++, j--)
        {
            if (s[i][j] != s[i - 1][j + 1])
                break;
        }
        if (i >= 3&&s[1][1]!='.')
        {
            c = s[1][1];
        }
        if (c == 'D')
        {
            cout << "DRAW\n";
        }
        else
            cout << c << '\n';
    }
}