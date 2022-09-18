#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{

    std::ios::sync_with_stdio(false);

    lol n;
    cin >> n;
    vector<lol> ind;
    string s = "";
    lol i = 0;
    while (i < n)
    {

        if (ind.size() == 0)
        {
            cout << "? " << 1 << " " << i + 1 << '\n';
            fflush(stdout);
            char c;
            cin >> c;
            s.push_back(c);
            ind.push_back(i);
            i++;
        }
        else
        {
            cout << "? " << 2 << " " << 1 << " " << i + 1 << '\n';
            fflush(stdout);
            lol x;
            cin >> x;
            if (x > ind.size())
            {
                cout << "? " << 1 << " " << i + 1 << '\n';
                char c;
                cin >> c;
                s.push_back(c);
                ind.push_back(i);
                i++;
            }
            else
            {
                for (lol j = ind.size() - 1; j >= 0; j--)
                {
                    cout << "? " << 2 << "  " << ind[j] + 1 << " " << i + 1 << '\n';
                    fflush(stdout);
                    cin >> x;
                    if (x == ind.size() - j)
                    {
                        s.push_back(s[ind[j]]);
                        ind.erase(ind.begin() + j);
                        ind.push_back(i);
                        i++;
                        break;
                    }
                }
            }
        }
    }
    cout << "! " << s << '\n';

    return 0;
}