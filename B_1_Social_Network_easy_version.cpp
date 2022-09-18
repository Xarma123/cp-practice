#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol n, k;
    cin >> n >> k;
    set<lol> mp;
    deque<lol> vect;
    for (lol i = 0; i < n; i++)
    {
        lol t;
        cin >> t;
        if (!mp.count(t))
        {
            if (vect.size() == k)
            {
                mp.erase(vect.back());
                vect.pop_back();
            }
            mp.insert(t);
            vect.push_front(t);
        }
    }
    cout << vect.size() << endl;
    for (lol i = 0; i < vect.size(); i++)
    {
        cout << vect[i] << " ";
    }

    return 0;
}