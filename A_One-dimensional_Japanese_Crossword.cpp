#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n;
    cin >> n;
    string s;
    cin >> s;
    vector<lol> ans;
    for (lol i = 0; i < s.size(); i++)
    {
        lol j = i + 1;
        while (j < s.size() && s[j] == s[i])
            j++;
        if (s[i] == 'B')
            ans.push_back(j - i);
        i = j - 1;
    }
    cout << ans.size() << endl;
    for (auto e : ans)
        cout << e << " ";

    return 0;
}