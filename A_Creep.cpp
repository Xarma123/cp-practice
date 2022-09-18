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
        lol a, b;
        cin >> a >> b;
        string ans = "";
        lol inv = 1;
        while (a > 0 && b > 0)
        {
            if (inv)
            {
                ans.push_back('0');
                a--;
                inv = 1 - inv;
            }
            else
            {
                ans.push_back('1');
                b--;
                inv = 1 - inv;
            }
        }
        while (a--)
        {
            ans.push_back('0');
        }
        while (b--)
        {
            ans.push_back('1');
        }
        cout << ans << endl;
    }

    return 0;
}