#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    string x;
    lol j, k;
    for (lol i = 0; i < s.size(); i++)
    {
        if (s[i] == '.')
            k = i;
        if (s[i] == 'e')
        {
            j = i;
            x = s.substr(i + 1);
        }
    }
    lol v = stol(x);
    s.erase(j);

    while (v > 0 && k + 1 < s.size())
    {
        swap(s[k], s[k + 1]);
        k++;
        v--;
    }
    if (s[s.size() - 1] == '.')
        s.pop_back();
    while (v--)
    {
        s.push_back('0');
    }
    k = -1;
    for (lol i = 0; i < s.size(); i++)
    {
        if (s[i] == '.')
            k = i;
    }
    if (k == -1)
        cout << s;
    else
    {
        if (s.substr(0, k) == "0" && s.substr(k) == ".0")
            cout << 0;
        else if (s.substr(0, k) == "0")
            cout << s;
        else if (s.substr(k) == ".0")
            cout << s.substr(0, k);
        else
            cout << s;
    }

    return 0;
}