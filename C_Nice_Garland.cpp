#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol n;
    cin >> n;
    string s;
    cin >> s;
    string q;
    string x[6] = {"RGB", "RBG", "GRB", "GBR", "BGR", "BRG"};
    lol ans = LONG_LONG_MAX;
    for (lol i = 0; i < 6; i++)
    {
        string f = "";
        lol c = 0;
        lol p = 0, p1 = 0;
        while (p < s.size())
        {
            if (s[p] != x[i][p1])
            {
                c++;
            }
            f.push_back(x[i][p1]);
            p++;
            p1++;
            if (p1 == 3)
                p1 = 0;
        }
        if (c < ans)
        {
            ans = c;
            q = f;
        }
    }
    cout << ans << endl;
    cout << q << endl;

    return 0;
}