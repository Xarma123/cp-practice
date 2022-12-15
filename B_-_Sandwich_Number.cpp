#include <bits/stdc++.h>
#define lol long long
using namespace std;
bool check(char c)
{
    return (c >= 'A' && c <= 'Z');
}
bool check(string a)
{
    for (auto c : a)
    {
        if (!(c >= '0' && c <= '9'))
            return false;
    }
    return (stoll(a) >= 100000 && stoll(a) <= 999999);
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s;
    cin >> s;
    if (s.size() == 8 && check(s[0]) && check(s[7]) && check(s.substr(1, 6)))
        cout << "Yes";
    else
        cout << "No";

    return 0;
}