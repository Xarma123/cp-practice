#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    lol c = 0;
    set<lol> index;
    for (lol i = 0; i < n; i++)
    {
        if (s[i] == 'a')
        {
            if (i + 2 < n)
            {
                if (s[i + 1] == 'b' && s[i + 2] == 'c')
                {
                    c++;
                    index.insert(i);
                    index.insert(i + 1);
                    index.insert(i + 2);
                }
            }
        }
    }
    while (q--)
    {
        lol p;
        char x;
        cin >> p >> x;
        if (s[p - 1] == x)
        {
            cout << c << endl;
        }
        else
        {
            if (index.count(p - 1))
            {
                c--;
                if (s[p - 1] == 'a')
                {
                    index.erase(p - 1);
                    index.erase(p);
                    index.erase(p + 1);
                }
                else if (s[p - 1] == 'b')
                {
                    index.erase(p - 2);
                    index.erase(p - 1);
                    index.erase(p);
                }
                else
                {
                    index.erase(p - 2);
                    index.erase(p - 1);
                    index.erase(p - 3);
                }
            }
            if (x == 'a')
            {
                if (p + 1 < n)
                {
                    if (s[p] == 'b' && s[p + 1] == 'c')
                    {
                        c++;
                        index.insert(p - 1);
                        index.insert(p);
                        index.insert(p + 1);
                    }
                }
            }
            else if (x == 'b')
            {
                if (p - 2 >= 0 && p < n)
                {
                    if (s[p - 2] == 'a' && s[p] == 'c')
                    {
                        c++;
                        index.insert(p - 2);
                        index.insert(p - 1);
                        index.insert(p);
                    }
                }
            }
            else
            {
                if (p - 3 >= 0)
                {
                    if (s[p - 3] == 'a' && s[p - 2] == 'b')
                    {
                        c++;
                        index.insert(p - 3);
                        index.insert(p - 2);
                        index.insert(p - 1);
                    }
                }
            }
            s[p - 1] = x;
            cout << c << endl;
        }
    }

    return 0;
}