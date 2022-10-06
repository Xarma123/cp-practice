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
        lol n;
        cin >> n;
        string s;
        cin >> s;
        string r = "";
        lol a = 1;
        lol i = 0, j = s.size() - 1;
        while (i <= j)
        {
            if (a)
            {
                if (s[i] == '0')
                    r = "0" + r;
                else
                    r = r + "1";
                i++;
            }
            else
            {
                if (s[j] == '1')
                    r = "1" + r;
                else
                    r = r + "0";
                j--;
            }
            a = 1 - a;
        }
        cout << r << endl;
    }

    return 0;
}