#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol n;
        cin >> n;
        lol a[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        map<lol, vector<lol>> mp;
        lol p = 0;
        for (lol i = 0; i < n; i++)
        {

            mp[a[i]].push_back(i);
        }

        for (auto i = mp.begin(); i != mp.end(); i++)
        {
            for (lol j = 0; j < (*i).second.size(); j++)
            {
                lol l = ((*i).second[j]) * ((*i).second.size() - j - 1);
                lol r = (n - (*i).second[j]) * (j); 
                
            }
        }
        cout << p << endl;
    }

    return 0;
}