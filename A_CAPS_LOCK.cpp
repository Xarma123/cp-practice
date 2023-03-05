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
    for (lol i = 0; i < s.size(); i++)
    {
        s[i] = toupper(s[i]);
    }
    cout << s;

    return 0;
}