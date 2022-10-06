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
        x.insert('a');
        x.insert('e');
        x.insert('i');
        x.insert('o');
        x.insert('u');
        bool ans = false;
        for (lol i = 0; i < s.size(); i++)
        {
            if (x.count(s[i]))
            {
                lol j = i + 1;
                while (j < s.size() && x.count(s[j]))
                    j++;
                if (j - i > 2)
                    ans = true;
                i = j - 1;
            }
        }
        if (ans)
            cout << "Happy" << endl;
        else
            cout << "Sad" << endl;
    }

    return 0;
}