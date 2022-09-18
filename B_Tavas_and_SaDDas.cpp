#include <bits/stdc++.h>
#define lol long long
using namespace std;
lol solve(string s)
{
    if (s == "4")
        return 1;
    if (s == "7")
        return 2;
    if (s[0] == '7')
    {
        return solve(s.substr(1)) + (1 << (s.size()));
    }
    else
        return solve(s.substr(1)) + (1 << (s.size() - 1));
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s;
    cin >> s;
    cout << solve(s);

    return 0;
}