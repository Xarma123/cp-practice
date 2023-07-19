#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        lol j;
        if (s[0] == 'Y')
            j = 1;
        else if (s[0] == 'e')
            j = 2;
        else if (s[0] == 's')
            j = 0;
        else
            j = -1;
        for (lol i = 1; i < s.size() && j != -1; i++)
        {
            if (j == 0)
            {
                if (s[i] != 'Y')
                {
                    j = -1;
                }
                else
                {
                    j++;
                    j %= 3ll;
                }
            }
            else if (j == 1)
            {
                if (s[i] != 'e')
                {
                    j = -1;
                }
                else
                {
                    j++;
                    j %= 3ll;
                }
            }
            else
            {
                if (s[i] != 's')
                {
                    j = -1;
                }
                else
                {
                    j++;
                    j %= 3ll;
                }
            }
        }
        if (j != -1)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}