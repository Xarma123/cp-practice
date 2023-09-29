#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n;
    cin >> n;
    string s;
    cin >> s;
    string b = s;
    vector<lol> op;
    for (lol i = 0; i < s.size() - 1; i++)
    {
        if (s[i] != 'W')
        {
            op.push_back(i);
            s[i] = 'W';
            if (s[i + 1] == 'W')
                s[i + 1] = 'B';
            else
                s[i + 1] = 'W';
        }
    }
    if (s.back() == 'W')
    {
        cout << op.size() << "\n";
        for (auto e : op)
            cout << e + 1 << " ";
        return 0;
    }
    s = b;
    op.clear();
    for (lol i = 0; i < s.size() - 1; i++)
    {
        if (s[i] != 'B')
        {
            op.push_back(i);
            s[i] = 'B';
            if (s[i + 1] == 'W')
                s[i + 1] = 'B';
            else
                s[i + 1] = 'W';
        }
    }
    if (s.back() == 'B')
    {
        cout << op.size() << "\n";
        for (auto e : op)
            cout << e + 1 << " ";
        return 0;
    }
    cout << -1;
}