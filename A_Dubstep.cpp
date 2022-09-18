#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s;
    cin >> s;
    string q = "";
    bool l = false;
    for (lol i = 0; i < s.size(); i++)
    {
        if (i + 2 < s.size())
        {
            if (s[i] == 'W' && s[i + 1] == 'U' && s[i + 2] == 'B')
            {
                if (l)
                {
                    q = q + " ";
                    l = false;
                }
                i = i + 2;
                continue;
            }
        }
        l = true;
        q.push_back(s[i]);
    }
    cout << q;

    return 0;
}