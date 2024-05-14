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
        string s;
        cin >> s;
        lol n = s.size();
        lol c = 0;
        for (lol i = 0; i < n; i++)
        {
            lol j = i + 1;
            while (j < n && s[j] == s[i])
            {
                j++;
            }
            i = j - 1;
            c++;
        }
        for (lol i = 1; i < n; i++)
        {
            if (s[i] == '1' && s[i - 1] == '0')
            {
                c--;
                break;
            }
        }
        cout << c << '\n';
    }

    return 0;
}