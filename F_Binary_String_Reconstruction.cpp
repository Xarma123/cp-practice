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
        lol n0, n1, n2;
        cin >> n0 >> n1 >> n2;
        string s = "0";
        bool o = false;
        bool y = false;
        if (n0 > 0 && n1 == 0 && n2 == 0)
            y = true;
        if (n1 > 0)
            o = true;
        while (n0--)
        {
            s.push_back('0');
        }
        char c = '1';
        while (n1--)
        {
            s.push_back(c);
            if (c == '1')
                c = '0';
            else
                c = '1';
        }
        bool x = false;
        if (s.back() == '0')
        {
            s.pop_back();
            x = true;
        }
        if (s.size() == 0)
            s.push_back('1');
        while (n2--)
        {
            s.push_back('1');
        }
        if ((o && x) || y)
            s.push_back('0');
        cout << s << endl;
    }

    return 0;
}