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
    set<char> x;
    for (auto e : s)
    {
        x.insert(tolower(e));
    }
    if (x.size() == 26)
        cout << "YES";
    else
        cout << "NO";

    return 0;
}