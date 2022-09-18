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
    lol l = 0;
    for (lol i = 0; i < s.size(); i++)
    {
        if ('a' <= s[i] && s[i] <= 'z')
            l++;
    }
    if (s.size() - l <= l)
    {
        for (lol i = 0; i < s.size(); i++)
            s[i] = tolower(s[i]);
    }
    else
    {
        for (lol i = 0; i < s.size(); i++)
            s[i] = toupper(s[i]);
    }
    cout << s;

    return 0;
}