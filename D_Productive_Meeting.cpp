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
        multiset<pair<lol, lol>, greater<pair<lol, lol>>> a;

        stack<pair<lol, lol>> x;
        for (lol i = 0; i < n; i++)
        {
            lol t;
            cin >> t;
            a.insert(make_pair(t, i));
        }

        auto i = a.begin();
        auto index = a.begin();
        index++;

        while ((*i).first != 0 && (*index).first != 0)
        {

            x.push(make_pair((*i).second, (*index).second));
            pair<lol, lol> a1 = make_pair((*i).first - 1, (*i).second);
            pair<lol, lol> a2 = make_pair((*index).first - 1, (*index).second);

            a.erase(i);
            a.erase(index);
            a.insert(a1);
            a.insert(a2);
            i = a.begin();
            index = a.begin();
            index++;
        }

        cout << x.size() << endl;

        while (!x.empty())
        {
            cout << x.top().first + 1 << " " << x.top().second + 1 << endl;
            x.pop();
        }
    }

    return 0;
}