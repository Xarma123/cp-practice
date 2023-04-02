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

        lol n;
        cin >> n;
        vector<lol> v;
        for (lol i = 1; i <= (1ll << n); i++)
        {
            v.push_back(i);
        }
        while (v.size() >= 4)
        {
            vector<lol> nx;
            for (lol i = 3; i < v.size(); i += 4)
            {

                cout << "? " << v[i] << " " << v[i - 3] << endl;
                lol c;
                cin >> c;
                if (c == 0)
                {
                    cout << "? " << v[i - 1] << " " << v[i - 2] << endl;
                    cin >> c;
                    if (c == 1)
                    {
                        nx.push_back(v[i - 1]);
                    }
                    else
                        nx.push_back(v[i - 2]);
                }
                else if (c == 1)
                {
                    cout << "? " << v[i] << " " << v[i - 2] << endl;
                    cin >> c;
                    if (c == 1)
                    {
                        nx.push_back(v[i]);
                    }
                    else
                        nx.push_back(v[i - 2]);
                }
                else
                {
                    cout << "? " << v[i - 3] << " " << v[i - 1] << endl;
                    cin >> c;
                    if (c == 1)
                    {
                        nx.push_back(v[i - 3]);
                    }
                    else
                        nx.push_back(v[i - 1]);
                }
            }
            v = nx;
        }
        if (v.size() >= 2)
        {
            cout << "? " << v[0] << " " << v[1] << endl;
            lol c;
            cin >> c;
            if (c == 1)
            {
                v.pop_back();
            }
        }
        cout << "! " << v.back() << endl;
    }
    return 0;
}