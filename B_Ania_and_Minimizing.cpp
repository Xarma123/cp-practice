#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    if (s.size() == 1)
    {
        if (k)
            cout << 0;
        else
            cout << s;
        return 0;
    }

    if (s[0] != '1' && k > 0)
    {
        k--;
        s[0] = '1';
    }
    for (lol i = 1; i < s.size() && k > 0; i++)
    {
        if (s[i] != '0')
        {
            s[i] = '0';
            k--;
        }
    }
    cout << s;
}