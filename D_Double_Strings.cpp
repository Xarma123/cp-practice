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
        unordered_set<string> s;
        string a[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
            s.insert(a[i]);
        }
        string q;
        for (lol i = 0; i < n; i++)
        {
            bool f = false;
            for (lol j = 1; j < a[i].size(); j++)
            {
                if (s.count(a[i].substr(0, j)))
                {
                    if (s.count(a[i].substr(j)))
                    {
                        f = true;
                        break;
                    }
                }
            }
            if (f)
                q.push_back('1');
            else
                q.push_back('0');
        }
        cout << q << endl;
    }

    return 0;
}