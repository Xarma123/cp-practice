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
        lol l, r;
        if (s[0] == '0')
        {
            l = 1, r = 1;
        }
        else
        {
            l = 2, r = 2;
        }
        cout << r - l + 1 << " ";
        for (lol i = 1; i < n - 1; i++)
        {
            if (s[i] == '0')
            {
                l = 1;
            }
            else
            {
                l = l + 1;
                r = i + 2;
            }
            cout << r - l + 1 << " ";
        }
        cout << endl;
    }

    return 0;
}