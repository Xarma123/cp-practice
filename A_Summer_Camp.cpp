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
    lol s = 1;
    string ans = "";
    while (ans.size() < n)
    {
        ans = ans + to_string(s);
        s++;
    }
    cout << ans[n - 1];

    return 0;
}