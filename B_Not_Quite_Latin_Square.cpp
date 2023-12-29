#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol t;
    cin >> t;
    while (t--)
    {
        string s[3];
        for (lol i = 0; i < 3; i++)
        {
            cin >> s[i];
            bool a = true, b = true, c = true;
            for (lol j = 0; j < 3; j++)
            {
                if (s[i][j] == 'A')
                    a = false;
                else if (s[i][j] == 'B')
                    b = false;
                else if (s[i][j] == 'C')
                    c = false;
            }
            if (a)
                cout << "A\n";
            else if (b)
                cout << "B\n";
            else if (c)
                cout << "C\n";
        }
    }

    return 0;
}
