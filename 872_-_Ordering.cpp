#include <bits/stdc++.h>
#define lol long long
using namespace std;
vector<string> ans;
map<char, vector<char>> mp;
map<char, lol> ind;
bool dfs(vector<char> q, string s)
{
    if (q.size() == 0)
    {
        ans.push_back(s);
        return true;
    }
    for (lol i = 0; i < q.size(); i++)
    {
        vector<char> q2 = q;
        q2.erase((q2.begin() + i));
        for (auto neh : mp[q[i]])
        {
            ind[neh]--;
            if (ind[neh] == 0)
                q2.push_back(neh);
            if (ind[neh] == -1)
                return false;
        }
        string s2 = s;
        s2 = s2 + " ";
        s2.push_back(q[i]);
        if (!dfs(q2, s2))
            return false;
        for (auto neh : mp[q[i]])
            ind[neh]++;
    }
    return true;
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol t;
    cin >> t;
    getchar();
    while (t--)
    {
        getchar();
        ans.clear();
        ind.clear();
        string s;
        getline(cin, s);
        mp.clear();
        stringstream ss(s);
        char c;

        while (ss >> c)
        {
            mp[c] = {};
        }
        getline(cin, s);

        stringstream s1s(s);
        string q;
        while (s1s >> q)
        {

            if (q[1] == '>')
            {
                ind[q[0]]++;
                mp[q[2]].push_back(q[0]);
            }
            else
            {
                ind[q[2]]++;
                mp[q[0]].push_back(q[2]);
            }
        }
        vector<char> z;
        for (auto c : mp)
        {
            if (ind[c.first] == 0)
            {

                z.push_back(c.first);
            }
        }

        if (dfs(z, ""))
        {
            for (auto s : ans)
                cout << s.substr(1) << endl;
        }
        else
        {
            cout << "NO" << endl;
        } 
    }
    return 0;
}