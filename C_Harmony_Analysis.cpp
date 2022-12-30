#include <bits/stdc++.h>
#define lol long long
using namespace std;

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol k;
    cin >> k;
    string s;
    for (lol i = 0; i < (1ll << k); i++)
    {
        s.push_back('+');
    }
    lol c = 1;
    cout << s << endl;
    for (lol i = 0; i < s.size() / 2; i++)
    {
        s[i] = '*';
    }
    for (lol i = 0; i < s.size() / 2 && c < (1ll << k); i++)
    {
        for (lol j = s.size() / 2 + i; j < s.size() && c < (1ll << k); j++, c++)
        {
            swap(s[i], s[j]);
            cout << s << endl;
            swap(s[i], s[j]);
        }
        s[i] = '+';
        s[s.size() / 2 + i] = '*';
    }

    return 0;
}