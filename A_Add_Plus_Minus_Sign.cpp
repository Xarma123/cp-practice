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
        lol tot = 0;
        if (s[0] == '1')
            tot++;
        for (lol i = 1; i < n; i++)
        {
            if (s[i] == '0')
                cout << '+';
            else
            {
                if (tot >= 0)
                {
                    cout << '-';
                    tot--;
                }
                else
                {
                    cout << '+';
                    tot++;
                }
            }
        }
        cout << endl;
    }

    return 0;
}