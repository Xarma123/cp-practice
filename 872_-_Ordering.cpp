#include <bits/stdc++.h>
#define lol long long
using namespace std;
vector<lol> z;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol t;
    cin >> t;
    while (t--)
    {
        cin.ignore();
        cin.ignore();
        string s;
        getline(cin, s);

        stringstream ss(s);
        char c;
        map<char, vector<char>> mp;
        while (ss >> c)
        {
            mp[c] = {};
        }
        getline(cin, s);
        cout << s << endl;
        map<char, lol> ind;
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

        for (auto c : mp)
        {
            if (ind[c.first] == 0)
            {
                z.push_back(c.first);
            }
        }
        for (auto e : z)
        {
            
        }
    }

    return 0;
}