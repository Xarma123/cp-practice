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
        string s;
        cin >> s;
        lol c = 0;
        for (auto e : s)
        {
            if (e == '1')
                c++;
        }
        if (c > 0 && (c % 2 == 0))
        {
            cout << "YES" << endl;
            lol l = -1;
            for (lol i = 0; i < n; i++)
            {
                if (s[i] != '1')
                {
                    if (i == 0)
                    {
                        cout << i + 1 << " " << n << '\n';
                    }
                    else
                    {
                        cout << i + 1 << " " << i << '\n';
                    }
                }
                else if (l == -1)
                    l = i;
            }
            vector<lol> ends;

            lol st = l;
            lol c = 0;
            while (1)
            {
                if (st == l)
                    c++;
                if (c == 2)
                    break;
                while (1)
                {
                    lol j = (st + 1) % n;
                    if (s[j] == '0')
                        st = j;
                    else
                        break;
                }
                ends.push_back(st);
                st++;
                st %= n;
            }
            cout << ends[0] + 1 << " " << ends[1]+1 << '\n';
            for (lol i = 2; i < ends.size(); i++)
            {
                cout << l + 1 << " " << ends[i] + 1 << '\n';
            }
        }
        else
            cout << "NO\n";
    }

    return 0;
}