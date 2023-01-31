#include <bits/stdc++.h>
#define lol long long
using namespace std;
string s;
lol i;
bool cmp(pair<lol, lol> a, pair<lol, lol> b)
{
    if (a.first < b.first)
        return true;
    else if (a.first == b.first)
    {
        if (s[a.second] - '0' > i && s[b.second] - '0' > i)
            return a.second < b.second;
        else if (s[a.second] > i + '0')
            return true;
        else if (s[b.second] > i + '0')
            return false;
        else
            return a.second > b.second;
    }
    else
        return false;
}
bool cmp2(pair<lol, string> a, pair<lol, string> b)
{
    if (a.first < b.first)
        return true;
    else if (a.first == b.first)
    {
        return a.second < b.second;
    }
    else
        return false;
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, k;
    cin >> n >> k;
    cin >> s;
    vector<pair<lol, string>> ans;
    for (i = 0; i < 10; i++)
    {

        vector<pair<lol, lol>> v;
        lol c = 0;
        for (lol j = 0; j < n; j++)
        {
            if (s[j] != char('0' + i))
            {
                v.push_back({abs(s[j] - i - '0'), j});
            }
            else
                c++;
        }

        sort(v.begin(), v.end(), cmp);

        string q = s;
        lol qq = 0;
        for (lol j = 0; j < k - c; j++)
        {
            q[v[j].second] = char('0' + i);
            qq += v[j].first;
        }
        ans.push_back({qq, q});
    }
    sort(ans.begin(), ans.end(), cmp2);
    cout << ans[0].first << '\n';
    cout << ans[0].second;

    return 0;
}