#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        cout << s[0];
        for (lol i = 1; i < s.size() - 1; i += 2)
        {
            cout << s[i];
        }
        cout << s.back() << '\n';
    }
}