#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string n;
    cin >> n;

    string ans = n;
    reverse(n.begin(), n.end());
    ans = ans + n;
    cout << ans;

    return 0;
}