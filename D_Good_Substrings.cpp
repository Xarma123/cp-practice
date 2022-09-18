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
    string w;
    cin >> w;
    lol k;
    cin >> k;
    unordered_set<string> x;
    for (lol i = 0; i < s.size(); i++)
    {
        string q = "";
        lol c = 0;
        for (lol j = i; j < s.size(); j++)
        {
            q.push_back(s[j]);
            if (w[s[j] - 'a'] == '0')
                c++;
            if (c <= k)
                x.insert(q);
        }
    }

    cout << x.size();

    return 0;
}