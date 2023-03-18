#include <bits/stdc++.h>
#define lol long long
using namespace std;
string solve(string s, string q)
{
    lol i = s.size() - 1;
    lol j = q.size() - 1;
    while (i >= 0 && j >= 0)
    {
        if (s[i] == '1' || q[j] == '1')
            s[i] = '1';
        i--;
        j--;
    }
    reverse(s.begin(), s.end());
    while (s.size() > 1 && s.back() == '0')
        s.pop_back();
    reverse(s.begin(), s.end());
    return s;
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n;
    cin >> n;
    string s;
    cin >> s;
    lol i = 0;
    while (i < n && s[i] == '0')
        i++;
    if (i < n)
    {
        lol j = i + 1;
        while (j < n && s[j] == '1')
            j++;
        lol l = n - j;
        vector<string> ans;
        for (lol k = i; k < j; k++)
        {
            string q = s.substr(k, l);
            ans.push_back(solve(s, q));
        }
        sort(ans.rbegin(), ans.rend());
        cout << ans[0];
    }
    else
        cout << "0";

    return 0;
}