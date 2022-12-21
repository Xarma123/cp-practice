#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n;
    cin >> n;
    string s;
    cin >> s;
    bool en = false;
    for (lol i = 0; i < s.size(); i++)
    {
        if (s[i] == '"')
        {
            if (en)
                en = false;
            else
                en = true;
        }
        if (!en && s[i] == ',')
        {
            s[i] = '.';
        }
    }
    cout << s;

    return 0;
}