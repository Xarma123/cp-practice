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
        char c;
        cin >> c;
        string s;
        cin >> s;
        bool f = true;
        for (lol i = 0; i < n; i++)
        {
            if (s[i] < c && f)
            {
                f = false;
                cout << c;
            }
            cout << s[i];
        }
        if (f)
            cout << c;
        cout << '\n';
    }

    return 0;
}