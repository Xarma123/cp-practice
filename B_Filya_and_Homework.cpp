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
    set<lol> x;
    while (n--)
    {
        lol v;
        cin >> v;
        x.insert(v);
    }
    if (x.size() == 1)
        cout << "YES";
    else if (x.size() == 2)
        cout << "YES";
    else if (x.size() == 3)
    {
        vector<lol> q;
        for (auto e : x)
            q.push_back(e);
        sort(q.begin(), q.end());
        if (q[1] - q[0] == q[2] - q[1])
            cout << "YES";
        else
            cout << "NO";
    }
    else
        cout << "NO";

    return 0;
}