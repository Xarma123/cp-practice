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
    bool ans = true;
    for (lol i = 1; i < n; i++)
    {
        if (s[i] == s[i - 1])
            ans = false;
    }
    if (ans)
        cout << "Yes";
    else
        cout << "No";

    return 0;
}