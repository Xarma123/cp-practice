#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol q;
    cin >> q;
    while (q--)
    {

        string s;
        cin >> s;
        string t;
        cin >> t;
        lol l = s.size() - t.size();
        if (l < 0)
        {
            cout << "NO" << endl;
        }
        else if (l == 0)
        {
            if (s == t)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
        else if (l == 1)
        {
            s.erase(s.begin());
            if (s == t)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
        else
        {
            if (l % 2 != 0)
            {

                l--;
            }
            if (l == 0)
            {
                if (s == t)
                    cout << "YES" << endl;
                else
                    cout << "NO" << endl;
            }
            else
            {
                lol index = t.size() - 1;

                lol si = s.size() - 1;

                while (index >= 0 && si >= 0)
                {
                    if (s[si] == t[index])
                    {
                        index--;

                        si--;
                    }
                    else
                    {

                        si = si - 2;
                    }
                }
                if (index < 0)
                    cout << "YES" << endl;
                else
                    cout << "NO" << endl;
            }
        }
    }
    return 0;
}