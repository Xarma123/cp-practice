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
        for (lol i = 0; i < n; i++)
        {
            if (s[i] == 'U')
                cout << 'D';
            else if (s[i] == 'D')
                cout << 'U';
            else
                cout << s[i];
        }
        cout << endl;
    }

    return 0;
}