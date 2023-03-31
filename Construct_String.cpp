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
            lol j = i + 1;
            while (j < n && s[j] == s[i])
                j++;
            if ((j - i) % 2 == 0)
            {
                cout << s[i] << s[i];
            }
            else
                cout << s[i];
            i = j - 1;
        }
        cout << '\n';
    }

    return 0;
}