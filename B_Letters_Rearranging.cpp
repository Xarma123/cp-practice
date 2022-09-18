#include <bits/stdc++.h>
#define lol long long
using namespace std;
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
        set<char> x;
        for (lol i = 0; i < s.size(); i++)
        {
            x.insert(s[i]);
        }
        sort(s.begin(), s.end());
        if (x.size() == 1)
            cout << -1 << endl;
        else
            cout << s << endl;
    }

    return 0;
}