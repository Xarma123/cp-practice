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
    while (n--)
    {
        string s;
        cin >> s;
        if (s.size() <= 10)
            cout << s << endl;
        else
        {
            cout << s[0] << s.size() - 2 << s.back() << endl;
        }
    }

    return 0;
}