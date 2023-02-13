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
        lol m;
        cin >> m;
        string q[m];
        map<string, vector<lol>> mp;
        for (lol i = 0; i < m; i++)
        {
            cin >> q[i];
            sort(q[i].begin(), q[i].end());
            mp[q[i]].push_back(i);
        }
        vector<string> ans;
        while (mp["nww"].size() > 0 && mp["iin"].size() > 0)
        {
            string a = to_string(mp["nww"].back() + 1) + " w " + to_string(mp["iin"].back() + 1) + " i";
            ans.push_back(a);
            mp["nww"].pop_back();
            mp["iin"].pop_back();
        }
        while (mp["iww"].size() > 0 && mp["inn"].size() > 0)
        {
            string a = to_string(mp["iww"].back() + 1) + " w " + to_string(mp["inn"].back() + 1) + " n";
            ans.push_back(a);
            mp["iww"].pop_back();
            mp["inn"].pop_back();
        }
        while (mp["www"].size() > 0 && mp["inn"].size() > 0 && mp["iin"].size() > 0)
        {
            string a = to_string(mp["www"].back() + 1) + " w " + to_string(mp["inn"].back() + 1) + " n";
            ans.push_back(a);
            a = to_string(mp["www"].back() + 1) + " w " + to_string(mp["iin"].back() + 1) + " i";
            ans.push_back(a);
            mp["www"].pop_back();
            mp["inn"].pop_back();
            mp["iin"].pop_back();
        }

        while (mp["inn"].size() > 0)
        {
            string a;
            if (mp["www"].size())
            {
                a = to_string(mp["www"].back() + 1) + " w " + to_string(mp["inn"].back() + 1) + " n";
                mp["nww"].push_back(mp["www"].back());
                mp["www"].pop_back();
            }
            else if (mp["nww"].size())
            {
                a = to_string(mp["nww"].back() + 1) + " w " + to_string(mp["inn"].back() + 1) + " n";
                mp["nnw"].push_back(mp["nww"].back());
                mp["nww"].pop_back();
            }
            ans.push_back(a);
            mp["inn"].pop_back();
        }
        while (mp["iin"].size() > 0)
        {
            string a;
            if (mp["www"].size())
            {
                a = to_string(mp["www"].back() + 1) + " w " + to_string(mp["iin"].back() + 1) + " i";
                mp["iww"].push_back(mp["www"].back());
                mp["www"].pop_back();
            }
            else if (mp["iww"].size())
            {
                a = to_string(mp["iww"].back() + 1) + " w " + to_string(mp["iin"].back() + 1) + " i";
                mp["iiw"].push_back(mp["iww"].back());
                mp["iww"].pop_back();
            }
            ans.push_back(a);
            mp["iin"].pop_back();
        }
        while (mp["iii"].size() > 0)
        {
            string a;
            if (mp["nww"].size())
            {
                a = to_string(mp["nww"].back() + 1) + " w " + to_string(mp["iii"].back() + 1) + " i";
                mp["nww"].pop_back();
            }
            else if (mp["www"].size())
            {
                a = to_string(mp["www"].back() + 1) + " w " + to_string(mp["iii"].back() + 1) + " i";
                mp["iww"].push_back(mp["www"].back());
                mp["www"].pop_back();
            }
            else if (mp["iww"].size())
            {
                a = to_string(mp["iww"].back() + 1) + " w " + to_string(mp["iii"].back() + 1) + " i";
                mp["iiw"].push_back(mp["iww"].back());
                mp["iww"].pop_back();
            }

            ans.push_back(a);
            mp["iiw"].push_back(mp["iii"].back());
            mp["iii"].pop_back();
        }
        while (mp["nnn"].size() > 0)
        {
            string a;
            if (mp["iww"].size())
            {
                a = to_string(mp["iww"].back() + 1) + " w " + to_string(mp["nnn"].back() + 1) + " n";
                mp["iww"].pop_back();
            }
            if (mp["nww"].size())
            {
                a = to_string(mp["nww"].back() + 1) + " w " + to_string(mp["nnn"].back() + 1) + " n";
                mp["nnw"].push_back(mp["nww"].back());
                mp["nww"].pop_back();
            }
            else if (mp["www"].size())
            {
                a = to_string(mp["www"].back() + 1) + " w " + to_string(mp["nnn"].back() + 1) + " n";
                mp["nww"].push_back(mp["www"].back());
                mp["www"].pop_back();
            }

            ans.push_back(a);
            mp["nnw"].push_back(mp["nnn"].back());
            mp["nnn"].pop_back();
        }
        while (mp["iiw"].size() > 0)
        {
            string a = to_string(mp["iiw"].back() + 1) + " i " + to_string(mp["nnw"].back() + 1) + " n";
            ans.push_back(a);
            mp["iiw"].pop_back();
            mp["nnw"].pop_back();
        }
        cout << ans.size() << endl;
        for (auto e : ans)
            cout << e << endl;
    }

    return 0;
}