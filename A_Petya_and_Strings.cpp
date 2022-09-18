#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s, s1;
    cin >> s >> s1;
    for (lol i = 0; i < s.size(); i++)
    {
        s[i] = tolower(s[i]);
        s1[i] = tolower(s1[i]);
    }
    if (s > s1)
        cout << 1;
    else if (s == s1)
        cout << 0;
    else
        cout << -1;

    return 0;
}