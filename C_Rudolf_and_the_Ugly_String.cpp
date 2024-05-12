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
        lol n;
        cin >> n;
        string s;
        cin >> s;
        // map mapie pie
        lol a = 0, b = 0, c = 0;
        for (lol i = 0; i + 2 < n; i++)
        {
            if (s[i] == 'm' && s[i + 1] == 'a' && s[i + 2] == 'p')
            {
                a++;
            }
            if (s[i] == 'p' && s[i + 1] == 'i' && s[i + 2] == 'e')
            {
                b++;
            }
            if (i + 4 < n)
            {
                if (s[i] == 'm' && s[i + 1] == 'a' && s[i + 2] == 'p' && s[i + 3] == 'i' && s[i + 4] == 'e')
                {
                    c++;
                }
            }
        }
        cout << a + b - c << '\n';
    }

    return 0;
}
