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
        lol ans = 1;
        for (lol i = 0; i < s.size(); i++)
        {
            x.insert(s[i]);
            if (x.size() >= 4)
            {
                ans++;
                x.clear();
                x.insert(s[i]);
            }
        }
        cout << ans << endl;
    }

    return 0;
}