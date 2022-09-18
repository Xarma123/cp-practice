#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol T;
    cin >> T;
    while (T--)
    {
        lol n;
        cin >> n;
        string a;
        cin >> a;
        string ans = "";
        lol k = -1;
        for (lol i = 0; i < a.size(); i++)
        {
            string a1 = a.substr(i);
            string b = a.substr(0, i);
            if ((n - i) % 2 != 0)
            {
                reverse(b.begin(), b.end());
            }
            a1 = a1 + b;
            if (ans == "")
            {
                ans = a1;
                k = i + 1;
            }
            else if (ans > a1)
            {
                ans = a1;
                k = i + 1;
            }
        }
        cout << ans << endl;
        cout << k << endl;
    }

    return 0;
}