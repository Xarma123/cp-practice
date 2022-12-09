#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n;
    string s;
    cin >> n >> s;
    if (n > 26)
        cout << -1;
    else
    {
        set<char> x;
        for (auto c : s)
            x.insert(c);
        cout << n - x.size();
    }

    return 0;
}