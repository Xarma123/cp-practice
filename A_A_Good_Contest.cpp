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
    bool ans = false;
    while (n--)
    {
        string s;
        lol a, b;
        cin >> s >> a >> b;
        if (a >= 2400 && b > a)
            ans = true;
    }
    if (ans)
        cout << "YES";
    else
        cout << "NO";

    return 0;
}