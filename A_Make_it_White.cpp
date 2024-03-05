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
        lol l = -1, r = -2;
        for (lol i = 0; i < n; i++)
        {
            if (s[i] == 'B')
            {
                r = i;
                if (l == -1)
                    l = i;
            }
        }
        cout << r - l + 1 << '\n';
    }

    return 0;
}
