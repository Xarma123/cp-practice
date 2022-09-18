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
    for (lol i = s.size() - 1; i > 0; i--)
    {
        if (s[i] >= '5')
        {
            s[i] = char('9' - s[i] + '0');
        }
    }
    if (s[0] >= '5' && s[0] < '9')
    {
        s[0] = char('9' - s[0] + '0');
    }
    cout << s;

    return 0;
}