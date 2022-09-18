#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol q;
    cin >> q;
    while (q--)
    {
        string s;
        string t;
        cin >> s >> t;
        bool a = false;
        for (lol i = 0; i < t.size(); i++)
        {
            if (t[i] == 'a')
                a = true;
        }
        if (a)
        {
            if (t.size() == 1)
                cout << 1 << endl;
            else
                cout << -1 << endl;
        }
        else
        {
            cout << (long long)powl(2, s.size()) << endl;
        }
    }

    return 0;
}