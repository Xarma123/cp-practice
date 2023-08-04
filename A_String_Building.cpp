#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        lol i;
        for (i = 0; i < s.size(); i++)
        {
            lol j = i + 1;
            while (j < s.size() && s[j] == s[i])
            {
                j++;
            }
            if (j - i == 1)
                break;
            i = j - 1;
        }
        if (i < s.size())
            cout << "NO\n";
        else
            cout << "YES\n";
    }
}