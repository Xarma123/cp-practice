#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s;
    cin >> s;
    string s2 = s;
    sort(s2.begin(), s2.end());
    reverse(s2.begin(), s2.end());
    for (lol i = 0; i < s.size(); i++)
    {
        if (s[i] != s2[i])
        {
            for (lol j = i + 1; j < s.size(); j++)
            {
                if (s[j] == s2[i])
                {
                    swap(s[j], s[i]);
                    break;
                }
            }
            break;
        }
    }
    cout << s << endl;

    return 0;
}