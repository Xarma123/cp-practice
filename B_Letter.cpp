#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);
    map<char, lol> f;
    for (auto c : s1)
    {
        if (c != ' ')
            f[c]++;
    }
    bool ans = true;
    for (auto c : s2)
    {
        if (c != ' ')
        {
            if (--f[c] < 0)
                ans = false;
        }
    }
    if (ans)
        cout << "YES";
    else
        cout << "NO";

    return 0;
}