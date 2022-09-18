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
        lol i;
        lol ca = 0;
        lol cb = 0;
        for (i = 0; i < s.size(); i++)
        {
            if (s[i] == 'B')
            {
                cb++;
            }
            else
                ca++;
            if (cb > ca)
                break;
        }
        if (i == s.size() && s[s.size() - 1] == 'B')
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}